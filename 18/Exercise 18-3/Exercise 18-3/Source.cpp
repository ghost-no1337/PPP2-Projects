#include "../../std_lib_facilities.h"

int strcmp(const char* s1, const char* s2)
{
	while (true) {
		if (*s1 < *s2)
			return -1;
		else if (*s1 > *s2)
			return 1;

		++s1;
		++s2;

		if (*s1 == 0 && *s2 != 0)
			return -1;
		if (*s2 == 0 && *s1 != 0)
			return 1;
		if (*s1 == 0 && *s2 == 0)
			return 0;
	}
}

int main()
{
	char s1[] = "Hello";
    char s2[] = "Hello";
	cout << strcmp(s1, s2) << '\n';

    char s3[] = "Apple";
	cout << strcmp(s1, s3) << '\n';

    char s4[] = "Microsoft";
	cout << strcmp(s1, s4) << '\n';

	keep_window_open();
}