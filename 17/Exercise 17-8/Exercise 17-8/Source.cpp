#include "../../std_lib_facilities.h"

int main()
{
    char ch;
    string s;
    while (cin.get(ch) && ch != '!')
        s += ch;

	cout << s << '\n';
    keep_window_open();
    return 0;
}