#include "../../std_lib_facilities.h"

int main()
{
	int v = 1;
	for (unsigned int i = 0; i < sizeof(v) * 8; ++i) {
		cout << v << ' ';
		v <<= 1;
	}

	short unsigned int a = ~0x0;
	short unsigned int b = 0x1;
	short unsigned int c = 0x1 << 15;
	short unsigned int d = 0x1 | (0x1 << 1) | (0x1 << 2) | (0x1 << 3);
	short unsigned int e = d << 12;
	short unsigned int f = 0x1;
	f = f | (f << 2) | (f << 4) | (f << 6) | (f << 8) | (f << 10) | (f << 12) | (f << 14);
	short unsigned int g = ~f;

	cout << '\n' << a << ' ' << hex << a << '\n'
		<< dec << b << ' ' << hex << b << '\n'
		<< dec << c << ' ' << hex << c << '\n'
		<< dec << d << ' ' << hex << d << '\n'
		<< dec << e << ' ' << hex << e << '\n'
		<< dec << f << ' ' << hex << f << '\n'
		<< dec << g << ' ' << hex << g << '\n';

	keep_window_open();
}