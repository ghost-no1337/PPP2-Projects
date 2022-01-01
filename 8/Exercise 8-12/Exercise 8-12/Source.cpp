#include "../../std_lib_facilities.h"

void print_until_ss(const vector<string> &v, string quit)
{
	int check = 0;
	for (string s : v) {
		if (s == quit)
			++check;
		if (check == 2)
			return;
		cout << s << '\n';
	}
}

void get_vector(vector<string> &v)
{
	for (string s; cin >> s; ) {
		if (s == "stop")
			return;
		v.push_back(s);
	}
}

int main()
{
	vector<string> test;
	get_vector(test);

	cout << '\n';
	print_until_ss(test, "test");

	keep_window_open("~~");
	return 0;
}