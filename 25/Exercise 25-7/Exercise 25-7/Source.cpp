#include "../../std_lib_facilities.h"

int main()
{
	for (int i = 0; i <= 400; ++i)
		cout << hex << i << '\n';

	for (int i = -200; i <= 200; ++i)
		cout << hex << i << '\n';

	keep_window_open();
}