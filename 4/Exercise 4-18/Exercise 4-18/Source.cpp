#include "../../std_lib_facilities.h"

//modified as Exercise 5-7
int main()
try {
	cout << "Type a, b and c:\n";
	double a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	double x1 = 0, x2 = 0;
	if (a == 0)
		error("not a quadratic equation");
	double delta = b*b - 4 * a * c;
	if (delta < 0)
		error("no real roots");
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);

	cout << "x1 == " << x1 << ".\n"
		<< "x2 == " << x2 << ".\n";
	keep_window_open();
	return 0;
}
catch(exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}