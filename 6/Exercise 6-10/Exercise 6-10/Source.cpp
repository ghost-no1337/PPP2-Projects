#include "../../std_lib_facilities.h"

int factorial(int x)
{
	if (x <= 0)
		error("not able to calculate factorial");
	int result = 1;
	for (int i = 1; i <= x; ++i)
		result *= i;
	return result;
}

double permutation(int a, int b)
{
	return factorial(a) / factorial(a - b);
}

double combination(int a, int b)
{
	return permutation(a, b) / factorial(b);
}

int main()
try {
	int a = 0, b = 0;
	string type;

	cout << "Enter two integers to calculate:\n";
	cin >> a >> b;
	cout << "Enter the type you want to calculate ('permutation' or 'combination':\n";
	cin >> type;

	if (a <= 0 || b <= 0)
		error("bad input (integers)");
	if (type != "permutation" && type != "combination")
		error("bad input (type of calculation)");

	if (type == "permutation")
		cout << "P(" << a << ", " << b << ") == " << permutation(a, b) << '\n';
	else if (type == "combination")
		cout << "C(" << a << ", " << b << ") == " << combination(a, b) << '\n';

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return -1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}