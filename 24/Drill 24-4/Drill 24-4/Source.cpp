#include "../../std_lib_facilities.h"
#include "../../Matrix.h"
#include "../../MatrixIO.h"
#include <complex>

using namespace Numeric_lib;

int main()
try {
	int sqrtint = 0;
	cin >> sqrtint;
	errno = 0;
	if (!errno)
		cout << sqrt(sqrtint) << '\n';
	else
		cout << "no square root\n";

	Matrix<double> md(10);
	for (int i = 0; i < 10; ++i) {
		int num;
		if (cin >> num)
			md[i] = num;
		else
			error("cin failed");
	}
	cout << md << '\n';

	int scale1 = 0, scale2 = 0;
	cin >> scale1 >> scale2;
	Matrix<double, 2> result(scale1, scale2);
	for (int i = 0; i < scale1; ++i)
		for (int j = 0; j < scale2; ++j)
			result[i][j] = md[i] * md[j];
	cout << result;

	Matrix<complex<double>> mcd(10);
	for (int i = 0; i < 10; ++i) {
		complex<double> num;
		if (cin >> num)
			mcd[i] = num;
		else
			error("cin failed");
	}
	complex<double> sum;
	for (int i = 0; i < 10; ++i)
		sum += mcd[i];
	cout << sum;

	Matrix<double, 2> md2(2, 3);
	cin >> md2;
	cout << md2;

	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}