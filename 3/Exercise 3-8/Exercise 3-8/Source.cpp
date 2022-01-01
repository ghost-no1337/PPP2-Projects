#include "../../std_lib_facilities.h"

int main()
{
	cout << "Type an interger: ";
	int number = 0;
	cin >> number;

	if (number % 2 == 1)
		cout << "The value " << number << " is an odd number.\n";
	else 
		cout << "The value " << number << " is an even number.\n";

	keep_window_open();
}