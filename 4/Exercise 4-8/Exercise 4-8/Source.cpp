#include "../../std_lib_facilities.h"

int main() 
{
	double sum = 1;
	for (int i = 2; i <= 64; ++i) {
		cout << "The sum is " << sum << ".\n";
		sum *= 3;
	}

	keep_window_open();
	return 0;
}