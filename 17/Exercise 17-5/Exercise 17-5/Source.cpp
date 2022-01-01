#include "../../std_lib_facilities.h"

const char* findx(const char* s, const char* x)
{
	for (int i = 0; s[i] != 0; ++i) {
		if (s[i] == x[0]) {
			if (x[1] == 0)
				return &s[i];
			for (int j = 1; x[j] != 0; ++j) {
				if (s[i + j] != x[j] && x[j] != 0)
					break;
				if (x[j + 1] == 0)
					return &s[i];
				if (s[i + j + 1] == 0)
					return 0;
			}
		}
	}
	return 0;
}

int main()
try {
	char* s = new char[14]{ "Hello, World!" };
	char* x = new char[6]{ "World" };
	const char* a = findx(s, x);
	cout << a << '\n';

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}