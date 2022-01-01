#include "../../std_lib_facilities.h"

bool is_palindrome(const string& s)
{
	string new_s;
	for (int i = s.length() - 1; i >= 0; --i)
		new_s += s[i];

	if (s == new_s)
		return true;
	return false;
}

bool is_palindrome(const char s[], int n)
{
	char* p = new char[n + 1];
	for (int i = 0; i < n; ++i)
		p[i] = s[n - 1 - i];

	if (*s == *p)
		return true;
	return false;
}

int main()
{
	string s1 = "anna";
	if (is_palindrome(s1))
		cout << s1 << " is a palindrome.\n";

	string s2 = "ida";
	if (!is_palindrome(s2))
		cout << s2 << " isn't a palindrome.\n";

	char s3[] = "petep";
	if (is_palindrome(s3))
		cout << s3 << " is a palinrome.\n";

	char s4[] = "homesick";
	if (!is_palindrome(s4))
		cout << s4 << " isn't a palindrome.\n";

	keep_window_open();
}