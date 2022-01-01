#include "../../std_lib_facilities.h"

char* add_size(const char* s) 
{
	if (s == 0) 
		return 0;

	int n = 0;
	while (s[n] != 0)
		++n;
	char* new_s = new char[n + 2];

	int i = 0;
	while (s[i] != 0) {
		new_s[i] = s[i];
		++i;
	}
	new_s[n + 1] = 0;

	return new_s;
}

int main()
{
	char* str = new char[1]{ 0 };

	char ch;
	while (cin.get(ch) && ch != '!') {
		str = add_size(str);
		int i = 0;
		while (true) {
			if (str[i] == 0) {
				str[i - 1] = ch;
				break;
			}
			++i;
		}
	}

	cout << str << '\n';
	keep_window_open();
	return 0;
}