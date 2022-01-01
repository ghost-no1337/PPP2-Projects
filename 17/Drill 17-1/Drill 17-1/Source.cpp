#include "../../std_lib_facilities.h"

ostream& print_array10(ostream& os, int* a)
{
	for (int i = 0; i < 10; ++i)
		os << a[i] << ' ';
	return os;
}

ostream& print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
		os << a[i] << ' ';
	return os;
}

int main()
{
	int* pi = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 10; ++i)
		cout << pi[i] << ' ';
	cout << '\n';
	delete pi;

	int* ten_int = new int[10]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
	print_array10(cout, ten_int);
	cout << '\n';
	delete ten_int;

	int* eleven_int = new int[11]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
	print_array(cout, eleven_int, 11);
	cout << '\n';
	delete eleven_int;

	int* twenty_int = new int[20]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
		110, 111, 112, 113, 114, 115, 116, 117, 118, 119 };
	print_array(cout, twenty_int, 20);
	cout << '\n';
	delete twenty_int;

	keep_window_open();
	return 0;
}