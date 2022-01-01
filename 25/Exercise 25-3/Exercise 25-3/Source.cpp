#include "../../std_lib_facilities.h"

int main()
{
	int i1 = 0x00000000;
	int i2 = 0xffffffff;
	int i3 = 0xaaaaaaaa;
	int i4 = 0x55555555;
	int i5 = 0xcccccccc;
	int i6 = 0x33333333;
	int i7 = 0xf0f0f0f0;
	int i8 = 0x0f0f0f0f;
	cout << hex << i1 << '\n' << i2 << '\n' << i3 << '\n' << i4 << '\n'
		<< i5 << '\n' << i6 << '\n' << i7 << '\n' << i8 << '\n';

	unsigned int ui1 = i1;
	unsigned int ui2 = i2;
	unsigned int ui3 = i3;
	unsigned int ui4 = i4;
	unsigned int ui5 = i5;
	unsigned int ui6 = i6;
	unsigned int ui7 = i7;
	unsigned int ui8 = i8;

	cout << hex << ui1 << '\n' << ui2 << '\n' << ui3 << '\n' << ui4 << '\n'
		<< ui5 << '\n' << ui6 << '\n' << ui7 << '\n' << ui8 << '\n';

	keep_window_open();
}