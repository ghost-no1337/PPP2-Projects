#include "../../std_lib_facilities.h"
#include "../../Matrix.h"
#include "../../MatrixIO.h"

using namespace Numeric_lib;

int main()
{
	cout << "char: " << sizeof(char) << '\n'
		<< "short: " << sizeof(short) << '\n'
		<< "int: " << sizeof(int) << '\n'
		<< "long: " << sizeof(long) << '\n'
		<< "float: " << sizeof(float) << '\n'
		<< "double: " << sizeof(double) << '\n'
		<< "int*: " << sizeof(int*) << '\n'
		<< "double*: " << sizeof(double) << '\n';

	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);

	cout << "a: " << sizeof(a) << '\n'
		<< "b: " << sizeof(b) << '\n'
		<< "c: " << sizeof(c) << '\n'
		<< "d: " << sizeof(d) << '\n'
		<< "e: " << sizeof(e) << '\n';

	cout << a << '\n'
		<< b << '\n'
		<< c << '\n'
		<< d << '\n';

	keep_window_open();
}