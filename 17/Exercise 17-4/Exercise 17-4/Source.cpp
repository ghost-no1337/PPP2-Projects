#include "../..//std_lib_facilities.h"

char* strdup_(const char* s)
{
	int size = 0;
	while (s[size] != 0)
		++size;
	char* string = new char[size];
	for (int i = 0; i <= size; ++i)
		string[i] = s[i];
	return string;
}

int main()
{
	char* s = new char[14]{ "Hello, world!" };
	char* copy = strdup_(s);
	cout << s << '\n'
		<< copy << '\n';

	keep_window_open();
	return 0;
}