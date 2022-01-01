#include "../../std_lib_facilities.h"

void classify(string s)
{
	cout << "\nThe result of " << s << " is:\n";
	for (char ch : s) {
		if (isalpha(ch))
			cout << ch << " is a letter.\n";
		if (isdigit(ch))
			cout << ch << " is a decimal digit.\n";
		if (isxdigit(ch))
			cout << ch << " is a hexademical digit.\n";
		if (isupper(ch))
			cout << ch << " is an uppercase letter.\n";
		if (islower(ch))
			cout << ch << " is a lowercase letter.\n";
		if (isalnum(ch))
			cout << ch << " is a letter or a decimal digit.\n";
	}
}

int main()
try {
	cout << "Please enter strings to classify (enter 'end' to end):\n";
	for (string s; cin >> s; ) {
		if (s == "end")
			break;
		classify(s);
	}

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