#include "../../std_lib_facilities.h"

class Rational
{
public:
	int numerator_show() const { return numerator; }
	int denominator_show() const { return denominator; }

	Rational(int, int);
	Rational(int);
	void division();
	double show();
private:
	int numerator;
	int denominator;
};

Rational::Rational(int i1, int i2)
	:numerator(i1), denominator(i2)
{
	if (i2 == 0)
		error("negative denominator");
	division();
}

Rational::Rational(int i)
	:numerator(i), denominator(1)
{
}

void Rational::division()
{
	vector<int> numerator_number;
	vector<int> denominator_number;

	bool numerator_positive = true;
	bool denominator_positive = true;
	if (numerator < 0) {
		numerator_positive = false;
		numerator *= -1;
	}
	if (denominator < 0) {
		denominator_positive = false;
		denominator *= -1;
	}

	vector<int> result_number;
	int result = 1;

	for (int i = 1; i <= numerator; ++i)
		if (numerator % i == 0)
			numerator_number.push_back(i);
	for (int i = 1; i <= numerator; ++i)
		if (denominator % i == 0)
			denominator_number.push_back(i);

	for (int i : numerator_number)
		for (int j : denominator_number)
			if (i == j)
				result_number.push_back(i);

	for (int i : result_number)
		result *= i;

	numerator /= result;
	denominator /= result;

	if (!numerator_positive)
		numerator *= -1;
	if (!denominator_positive)
		denominator *= -1;
}

double Rational::show()
{
	return double(numerator) / double(denominator);
}

Rational operator+ (const Rational &r1, const Rational &r2)
{
	int result_numerator = r1.numerator_show() * r2.denominator_show() + r1.denominator_show() * r2.numerator_show();
	int result_denominator = r1.denominator_show() * r2.denominator_show();
	Rational result(result_numerator, result_denominator);
	result.division();
	return result;
}

Rational operator- (const Rational &r1, const Rational &r2)
{
	int result_numerator = r1.numerator_show() * r2.denominator_show() - r1.denominator_show() * r2.numerator_show();
	int result_denominator = r1.denominator_show() * r2.denominator_show();
	Rational result(result_numerator, result_denominator);
	result.division();
	return result;
}

Rational operator* (const Rational &r1, const Rational &r2)
{
	int result_numerator = r1.numerator_show() * r2.numerator_show();
	int result_denominator = r1.denominator_show() * r2.denominator_show();
	Rational result(result_numerator, result_denominator);
	result.division();
	return result;
}

Rational operator/ (const Rational &r1, const Rational &r2)
{
	int result_numerator = r1.numerator_show() * r2.denominator_show();
	int result_denominator = r1.denominator_show() * r2.numerator_show();
	Rational result(result_numerator, result_denominator);
	result.division();
	return result;
}

bool operator== (const Rational &r1, const Rational &r2)
{
	if (r1.numerator_show() == r2.numerator_show() && r1.denominator_show() == r2.denominator_show())
		return true;
	return false;
}

bool operator!= (const Rational &r1, const Rational &r2)
{
	return !(r1 == r2);
}

ostream &operator<< (ostream &os, const Rational &r)
{
	return os << r.numerator_show() << '/' << r.denominator_show();
}

int main()
try {
	Rational r1(1, 2);
	Rational r2(2, 4);
	Rational r3(10, 15);
	if (r1 == r2)
		cout << r1 << '\t' << r2 << '\t' << r3 << '\n'
		<< r1 + r3 << '\t' << r1 - r3 << '\t' << r1 * r3 << '\t' << r1 / r3 << '\n'
		<< r1.show() << '\t' << r3.show() << '\n';
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