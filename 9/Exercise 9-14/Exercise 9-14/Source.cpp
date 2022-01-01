#include "../../std_lib_facilities.h"

constexpr double DKK_per_USD = 6.6586;

class Money
{
public:
	double show() const;
	string show_currency() const { return currency; }
	
	Money(string, double);
	Money();
	void fit_in(double); // Apply 4/5 rounding rule
	void convert(string);
private:
	string currency;
	long int cents;
};

double Money::show() const
{
	return double(cents) / 100;
}

Money::Money(string s, double d)
	:currency(s), cents(int(d * 100))
{
	if (s != "USD" && s != "DKK")
		error("unsupported currency");
	if (cents < 0)
		error("negative value");
	fit_in(d * 100);
}

Money::Money()
	:currency("USD"), cents(0)
{
}

void Money::fit_in(double d)
{
	if (d - cents >= 0.5)
		++cents;
}

void Money::convert(string s)
{
	if (currency == "USD" && s == "DKK") {
		double result = cents * DKK_per_USD;
		cents = result;
		fit_in(result);
		currency = "DKK";
	}
	else if (currency == "DKK" && s == "USD") {
		double result = cents / DKK_per_USD;
		cents = result;
		fit_in(result);
		currency = "USD";
	}
	else if (currency == s) {}
	else
		error("unsupported convert");
}

Money operator+ (Money m1, Money m2)
{
	m1.convert("USD");
	m2.convert("USD");
	Money result("USD", m1.show() + m2.show());
	return result;
}

ostream &operator<< (ostream &os, Money &m)
{
	return os << m.show_currency() << ' ' << m.show() << '\n';
}

istream &operator>> (istream &is, Money &m)
{
	string currency;
	double value;
	is >> currency >> value;
	if (!is) 
		return is;
	m = Money(currency, value);
	return is;
}

int main()
try {
	Money test1, test2;
	cin >> test1 >> test2;
	cout << test1 + test2;
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