#include "../../std_lib_facilities.h"

ostream& print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
		os << a[i] << ' ';
	return os;
}

int main()
{
	int seven = 7;
	int* p1 = &seven;
	cout << *p1 << '\n';

	int seven_int[7]{ 1, 2, 4, 8, 16, 32, 64 };
	int* p2 = &seven_int[0];
	print_array(cout, p2, 7);
	cout << '\n';

	int* p3 = p2;
	p2 = p1;
	p2 = p3;
	cout << p1 << ' ' << p2 << " \n"
		<< *p1 << ' ' << *p2 << " \n";

	int ten_int[10]{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	p1 = &ten_int[0];
	int ten_int2[10]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
	p2 = &ten_int2[0];
	p2 = p1;
	print_array(cout, p1, 10);
	cout << '\n';
	print_array(cout, p2, 10);
	cout << '\n';

	keep_window_open();
	return 0;
}