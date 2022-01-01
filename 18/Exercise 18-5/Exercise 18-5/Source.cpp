#include "../../std_lib_facilities.h"

string cat_dot(const string& s1, const string& s2)
{
	return s1 + '.' + s2;
}

int main()
{
	string s1 = "Niels";
	string s2 = "Bohr";
	cout << cat_dot(s1, s2) << '\n';

	keep_window_open();
}