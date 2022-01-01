#include "../../std_lib_facilities.h"

int main()
{
	int i1 = 1, i2 = 1, i0 = 0;
	cout << i1 << '\n' << i2 << '\n';
	while (i2 <= 0x4fffffff) {
		i0 = i1;
		i1 = i2;
		i2 = i0 + i1;
		cout << i2 << '\n';
	}
	keep_window_open();
	return 0;
}