#include "../../std_lib_facilities.h"

int main()
{
	regex pattern;
	string pat;
	getline(cin, pat);
	try {
		pattern = pat;
		cout << "pattern: " << pat << '\n';
	}
	catch (exception& e) {
		cout << pat << " is not a valid regular expression\n";
		exit(1);
	}

	string iname;
	getline(cin, iname);
	ifstream ifs{ iname };

	int lineno = 0;
	for (string line; getline(ifs, line); ) {
		++lineno;
		smatch matches;
		if (regex_search(line, matches, pattern))
			cout << "line " << lineno << ": " << line << '\n';
	}

	keep_window_open();
}