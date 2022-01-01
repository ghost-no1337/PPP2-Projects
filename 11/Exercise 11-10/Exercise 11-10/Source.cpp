#include "../../std_lib_facilities.h"

vector<string> split(const string& s)
{
	vector<string> result;
	stringstream ss{ s };
	for (string substring; ss >> substring; )
		result.push_back(substring);
	return result;
}

int main()
{
	string s;
	getline(cin, s);
	vector<string> output = split(s);
	for (string str : output) {
		cout << str << '\n';
	}

	keep_window_open();
	return 0;
}