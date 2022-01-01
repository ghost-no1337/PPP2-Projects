#include "../../std_lib_facilities.h"
#include "Chrono.h" // Using "Chrono.h" by Bjarne Stroustrup

using namespace Chrono;

Date today(2016, Date::Month::jul, 29);

// Class Genre:
enum class Genre
{
	fiction = 1, nonfiction, periodical, biography, children
};

ostream &operator<< (ostream &os, const Genre &g)
{
	switch (int(g)) {
	case 1:
		return os << "fiction";
	case 2:
		return os << "nonfiction";
	case 3:
		return os << "periodical";
	case 4:
		return os << "biography";
	case 5:
		return os << "children";
	}
}

// Class Book:
class Book
{
public:
	string ISBN_show() const { return ISBN; }
	string title_show() const { return title; }
	string author_show() const { return author; }
	Date copyright_show() const { return copyright_date; }
	Genre genre_show() const { return book_genre; }
	bool checked_out_show() const { return checked_out; };

	Book(string, string, string, Date, Genre);
	void check_in();
	void check_out();
private:
	string ISBN;
	string title;
	string author;
	Date copyright_date;
	Genre book_genre;
	bool checked_out = false;
};

Book::Book(string isbn, string t, string a, Date cd, Genre g)
	:ISBN(isbn), title(t), author(a), copyright_date(cd), book_genre(g)
{
	int counter = 0;
	bool successful = true;
	for (int i = 0; i < isbn.size(); ++i)
		switch (isbn[i]) {
		case '-':
			++counter;
			break;
		default:
			if (counter < 3)
				if (!isdigit(isbn[i]))
					successful = false;
				else if (counter == 3) {
					if (i + 1 != isbn.size())
						successful = false;
					if (!(isdigit(isbn[i])) || isalpha(isbn[i]))
						successful = false;
				}
			if (!successful)
				error("Bad input: ISBN number");
		}
}

void Book::check_in()
{
	if (!checked_out)
		error("The book has been in the library.");
	checked_out = false;
}

void Book::check_out()
{
	if (checked_out)
		error("The book has been checked out.");
	checked_out = true;
}

bool operator== (Book &b1, Book &b2)
{
	if (b1.ISBN_show() == b2.ISBN_show())
		return true;
	return false;
}

bool operator!= (Book &b1, Book &b2)
{
	if (b1 == b2)
		return false;
	return true;
}

ostream &operator<< (ostream &os, const Book &b)
{
	return os << "Title: " << b.title_show() << '\n'
		<< "Author: " << b.author_show() << '\n'
		<< "ISBN: " << b.ISBN_show() << '\n'
		<< "Genre: " << b.genre_show() << '\n';
}

// Class Patron:
class Patron
{
public:
	string name_show() const { return name; }
	string card_number_show() const { return card_number; }
	int fee_show() const { return fee; }

	Patron(string, string);
	void set_fee(int);
	bool fee_check();
private:
	string name;
	string card_number;
	int fee = 0;

	bool checked_out = false;
};

Patron::Patron(string n, string cn)
	:name(n), card_number(cn)
{
}

void Patron::set_fee(int i)
{
	fee += i;
}

bool Patron::fee_check()
{
	if (fee != 0)
		return true;
	return false;
}

bool operator== (Patron &p1, Patron &p2)
{
	if (p1.card_number_show() == p2.card_number_show())
		return true;
	return false;
}

//Class Transaction:
struct Transaction
{
	Book b;
	Patron p;
	Date d;

	Transaction(Book, Patron, Date);
};

Transaction::Transaction(Book bk, Patron pt, Date dt)
	:b(bk), p(pt), d(dt)
{
}

// Class Library:
class Library
{
public:
	void add_book(string, string, string, int, Date::Month, int, Genre);
	void add_patron(string, string);

	void check_out(Book, Patron);
	vector<Patron> owe_fee_patrons();
};

vector<Book> book_vector;
vector<Patron> patron_vector;

void Library::add_book(string isbn, string t, string a, int year, Date::Month m, int day, Genre g)
{
	Date d(year, m, day);
	Book b(isbn, t, a, d, g);
	book_vector.push_back(b);
}

void Library::add_patron(string n, string cn)
{
	Patron p(n, cn);
	patron_vector.push_back(p);
}

vector<Transaction> transaction_vector;

void Library::check_out(Book b, Patron p)
{
	// Check Book
	bool book_check = false;
	for (Book b1 : book_vector)
		if (b1 == b)
			book_check = true;
	if (!book_check)
		error("This book isn't in the library.");

	// Check Patron
	bool patron_check = false;
	for (Patron p1 : patron_vector)
		if (p1 == p)
			patron_check = true;
	if (!patron_check)
		error("This user isn't in the library.");

	// Check out
	if (p.fee_check())
		error("This user still owes the library some money.");
	b.check_out();
	Transaction t(b, p, today);
	transaction_vector.push_back(t);
}

vector<Patron> Library::owe_fee_patrons()
{
	vector<Patron> result;
	for (Patron p : patron_vector)
		if (p.fee_show() != 0)
			result.push_back(p);
	return result;
}

// Main:
int main()
try {
	Library lib;

	lib.add_book("0-321-99278-4", "Programming: Principles and Practice Using C++ (Second Edition)", "Bjarne Stroustrup", 2014, Date::Month::jun, 4, Genre::periodical);
	cout << book_vector[0];

	lib.add_patron("Junqi Xie", "310112200105295619");
	cout << patron_vector[0].name_show() << '\n'
		<< patron_vector[0].card_number_show() << '\n';

	lib.check_out(book_vector[0], patron_vector[0]);
	if (book_vector[0].checked_out_show())
		cout << "The book is checked out.\n";
	else cout << "The book is in the library.\n";

	patron_vector[0].set_fee(5);
	vector<Patron> v = lib.owe_fee_patrons();
	for (Patron p : v)
		cout << p.name_show()<<'\n';

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}