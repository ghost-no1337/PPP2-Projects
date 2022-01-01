#include "../../std_lib_facilities.h"

vector<string> units = { " one", " ten", " hundred", " thousand" };

void show_digits(const string& s)
//i > 0 && i <= 4;
{
	cout << s;
	cout << " is ";

	for(int i = s.size(); i > 0; --i)
	{
		if (s[s.size() - i] == 1)
			cout << s[s.size() - i] << units[i - 1];
		else
			cout << s[s.size() - i] << units[i - 1] << 's';

		if (i != 1)
			cout << " and ";
		else
			cout << '\n';
	}
}

int main()
try {
	string number;
	cin >> number;
	for (char ch : number)
		if (!isdigit(ch))
			error("not a number");

	if (number.size() > 4)
		error("not able to handle this");
	show_digits(number);

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error!\n";
	keep_window_open();
	return -1;
}