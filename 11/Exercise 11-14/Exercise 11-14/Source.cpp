#include "../../std_lib_facilities.h"

int alpha = 0, digit = 0, xdigit = 0, upper = 0, lower = 0, alnum = 0;

void classify(string s)
{
	for (char ch : s) {
		if (isalpha(ch))
			++alpha;
		if (isdigit(ch))
			++digit;
		if (isxdigit(ch))
			++xdigit;
		if (isupper(ch))
			++upper;
		if (islower(ch))
			++lower;
		if (isalnum(ch))
			++alnum;
	}
}

int main()
try {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		error("can't open input file");

	for (string s; ifs >> s; ) {
		if (s == "end")
			break;
		classify(s);
	}
	cout << "Alpha: " << alpha << '\n'
		<< "Digit: " << digit << '\n'
		<< "XDigit: " << xdigit << '\n'
		<< "Upper: " << upper << '\n'
		<< "Lower: " << lower << '\n'
		<< "Alnum: " << alnum << '\n';

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open("~~");
	return -1;
}