// Using the example code of Chapter 9.7.4

#include "../../std_lib_facilities.h"

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month& operator++(Month &m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	return m;
}

class Date {
public:
	Date(int yy, Month mm, int dd) 
		: y(yy), m(mm), d(dd) 
	{
		if (int(mm) < int(Month::jan) || int(mm) > int(Month::dec))
			error("Bad input: Month");
		if (dd < 1 || dd>31)
			error("Bad input: Day");
	}

	int   day()   const { return d; }
	Month month() const { return m; }
	int   year()  const { return y;	}

	void add_day(int n);
	void add_month(int n);
	void add_year(int n);
private:
	int   y;
	Month m;
	int   d;
};

int days_in_month(Month m)
{
	switch (m) {
	case Month::feb:
		return 28;
		break;
	case Month::apr: case Month::jun: case Month::sep: case Month::nov:
		return 30;
		break;
	default:
		return 31;
		break;
	}
}

void Date::add_day(int n) 
{
	if (n < 0)
		error("negative day");
	d += n;
	while (days_in_month(m) < d) {
		if (m == Month::dec) {
			d -= days_in_month(m);
			++m;
			++y;
		}
		else {
			d -= days_in_month(m);
			++m;
		}
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' << int(d.month())
		<< ',' << d.day()
		<< ')';
}

int main()
try {
	Date today = { 1978, Month::jun, 25 };
	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << "today: " << today << '\n'
		<< "tomorrow: " << tomorrow << '\n';

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