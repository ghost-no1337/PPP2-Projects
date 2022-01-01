#include "../../std_lib_facilities.h"

int main()
{
	cout << "Type in two integers: ";
	int val1;
	int val2;
	cin >> val1 >> val2;

	if (val1 > val2)
		cout << "val1 is bigger than val2.\n";
	else if (val1 < val2)
		cout << "val1 is smaller than val2.\n";

	cout << "The sum of val1 and val2 is " << val1 + val2 << '\n'
		<< "The difference of val1 and val2 is " << val1 - val2 << '\n'
		<< "The product of val1 and val2 is " << val1 * val2 << '\n'
		<< "The ratio of val1 and val2 is " << val1 / val2 << '\n';

	keep_window_open();
}