#include "../../std_lib_facilities.h"

string to_iso(string s) {
	regex date{ R"(\d{2}/\d{2}/\d{4})" };
	smatch matches;
	if (regex_match(s, matches, date)) {
		ostringstream oss;
		oss << string(matches[0], 6, 4) << '-' << string(matches[0], 0, 2) << '-' << string(matches[0], 3, 2);
		return oss.str();
	}
}

int main()
{
	string iname;
	cin >> iname;
	ifstream ifs{ iname };

	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	regex line_pat{ R"(^([\w ]+)(\d{2}/\d{2}/\d{4})([\w ]+)$)" };

	for (string line; getline(ifs, line); ) {
		smatch matches;
		if (regex_match(line, matches, line_pat))
			ofs << matches[1] << to_iso(matches[2]) << matches[3];
		else
			ofs << line;
	}

	keep_window_open();
}