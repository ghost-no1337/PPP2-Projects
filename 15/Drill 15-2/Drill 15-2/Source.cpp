#include "../../std_lib_facilities.h"

struct Person
{
	string name() const { return first_nme + ' ' + second_nme; }
	int age() const { return ag; }

	void set_name(string s1, string s2) { first_nme = s1; second_nme = s2; }
	void set_age(int i) { ag = i; }

	Person(string s1 = "", string s2 = "", int n = 0)
		:first_nme{ s1 }, second_nme{ s2 }, ag { n } {
		if (n < 0 || n >= 150)
			error("age out of range");
		for (char ch : (s1 + s2)){
			switch (ch) {
			case ';': case ':': case '"': case '\'': case '[': case ']':
			case '*': case '&': case '^': case '%': case '$': case '#':
			case '@': case '!':
				error("bad name input");
			}
		}
	}
private:
	string first_nme;
	string second_nme;
	int ag;
};

ostream& operator << (ostream& os, Person& p)
{
	return os << "Name: " << p.name() << '\n'
		<< "Age: " << p.age() << '\n';
}

istream& operator >> (istream& is, Person& p)
{
	string first_name;
	string second_name;
	int age;
	if (is >> first_name >> second_name >> age) {
		p.set_name(first_name, second_name);
		p.set_age(age);
		return is;
	}
}

int main()
try {
	vector<Person> vp;
	cout << "Type a sequence of Person. Type \"NoName NoName 0\" to stop.\n";
	for (Person p; cin >> p; ) {
		if (p.name() == "NoName NoName" && p.age() == 0)
			break;
		vp.push_back(p);
	}
	for (int i = 0; i < vp.size(); ++i)
		cout << vp[i];

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open("~~");
	return -1;
}