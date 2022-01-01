#include "../../std_lib_facilities.h"

constexpr double kelvin_zero = -273.15;

double c2k(double degree)
// degree >= -273.15
{
	if (degree < kelvin_zero)
		error("below absolute zero");
	degree -= kelvin_zero;
	return degree;
}

double k2c(double degree)
// degree >= 0
{
	if (degree < 0)
		error("below absolute zero");
	degree += kelvin_zero;
	return degree;
}

int main()
try {
	cout << "Type degrees with unit ('c' for Celsius, 'k' for Kelvin):\n";
	double degree = 0, result = 0;
	char unit = 0;
	cin >> degree >> unit;

	switch (unit) {
	case 'c':
		result = c2k(degree);
		break;
	case 'k':
		result = k2c(degree);
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