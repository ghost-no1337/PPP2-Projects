#include"../../std_lib_facilities.h"

int main() 
{
	cout << "Type 'zero' or 'one' or 'two' or 'three' or 'four' :";
	string spell_out;
	cin >> spell_out;
	if (spell_out == "zero")
		cout << "0\n";
	else if (spell_out == "one")
		cout << "1\n";
	else if (spell_out == "two")
		cout << "2\n";
	else if (spell_out == "three")
		cout << "3\n";
	else if (spell_out == "four")
		cout << "4\n";
	else
		cout << "not a number I know\n";

	keep_window_open();
}