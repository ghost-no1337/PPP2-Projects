#include "../../std_lib_facilities.h"

constexpr double kelvin_zero = -273.15;

double c2f(double degree)
// degree >= -273.15
{
	if (degree < kelvin_zero)
		error("below absolute zero.");
	degree = 9.0 / 5 * degree + 32;
	return degree;
}

double f2c(double degree)
// return degree >= 0
{
	degree = (degree - 32)*5.0 / 9;
	if (degree < kelvin_zero)
		error("below absolute zero.");
	return degree;
}

int main()
try {
	cout << "Type degrees with unit ('c' for Celsius, 'f' for Fahrenheit):\n";
	double degree = 0, result = 0;
	char unit = 0;
	cin >> degree >> unit;

	switch (unit) {
	case 'c':
		result = c2f(degree);
		break;
	case 'f':
		result = f2c(degree);
		break;
	default:
		error("not a correct unit.");
		break;
	}

	cout << result << '\n';
	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown errors\n";
	keep_window_open();
	return -1;
}