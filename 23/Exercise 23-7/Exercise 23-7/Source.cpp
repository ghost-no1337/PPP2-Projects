#include "../../std_lib_facilities.h"

int main()
{
	string iname;
	cin >> iname;
	ifstream is{ iname };

	regex pat{ R"(\d{4} ?\d{4} ?\d{4} ?\d{4})" };
	int lineno = 0;
	for (string line; getline(is, line); ) {
		++lineno;
		smatch matches;
		if (regex_search(line, matches, pat))
			cout << lineno << ": " << line << '\n';
	}

	keep_window_open();
}