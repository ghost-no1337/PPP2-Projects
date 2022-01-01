#include "../../std_lib_facilities.h"

int get_number(const char* s)
{
	int i = 0;
	while (true) {
		if (*s == 0)
			return i;
		++i;
		++s;
	}
}

char* cat_dot(const char* s1, const char* s2, const char* separator)
{
	char* p = new char[get_number(s1) + get_number(s2) + get_number(separator) + 1];
	int i = 0;
	for (int j = 0; ; ++j) {
		if (s1[j] == 0)
			break;
		p[i] = s1[j];
		++i;
	}
	for (int j = 0; ; ++j) {
		if (separator[j] == 0)
			break;
		p[i] = separator[j];
		++i;
	}
	for (int j = 0; ; ++j) {
		if (s2[j] == 0)
			break;
		p[i] = s2[j];
		++i;
	}
	p[i] = 0;
	return p;
}

int main()
{
	char s1[] = "Niels";
	char s2[] = "Bohr";
	cout << cat_dot(s1, s2, ".") << '\n';

	keep_window_open();
}