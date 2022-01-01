#include "../../std_lib_facilities.h"

void to_lower(char* s)
{
	for(int i = 0; s[i] != 0; ++i)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
}

int main()
{
	char* s = new char[14] {"Hello, world!"};
	to_lower(s);
	cout << s << '\n';

	keep_window_open();
	return 0;
}