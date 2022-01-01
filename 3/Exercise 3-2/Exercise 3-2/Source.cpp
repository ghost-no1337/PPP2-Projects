#include "../../std_lib_facilities.h"

int main() 
{
	cout << "This program enables you to convert from mile to kilometers.\n"
		<< "Type the mile number: ";
	double mile;
	cin >> mile;
	if (mile < 0)
		simple_error("no negative miles");
	cout << "It's " << mile * 1.609 << " kilometers.\n";
	keep_window_open();
}