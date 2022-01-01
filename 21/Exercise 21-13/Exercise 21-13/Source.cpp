#include "../../std_lib_facilities.h"
#include <map>

void clean_txt(map<string, int>& words, istream& is)
{
	ostringstream oss;
	for (char ch; is.get(ch);) {
		if (ispunct(ch) && ch != '\'')
			ch = ' ';
		oss << char(tolower(ch));
	}

	istringstream iss{ oss.str() };
	for (string s; iss >> s;) {
		if (s == "can't")
			++words["cannot"];
		else if (s == "won't") {
			++words["will"];
			++words["not"];
		}
		else if (s == "'" || s.size() == 2 && s[0] == '\'') { }
		else if (s.size() >= 3 && s[s.size() - 2] == '\'') {
			switch (s.back()) {
			case 'm':
				++words["am"];
				break;
			case 's':
				++words["is"];
				break;
			case 't':
				++words["not"];
				++words[s.substr(0, s.size() - 3)];
				break;
			default:
				error("unexpected letter in ", s);
				break;
			}
			if (s[s.size() - 1] != 't')
				++words[s.substr(0, s.size() - 2)];
		}
		else if (s.size() >= 4 && s[s.size() - 3] == '\'') {
			switch (s[s.size() - 2]) {
			case 'l':
				++words["will"];
				break;
			case 'r':
				++words["are"];
				break;
			case 'v':
				++words["have"];
				break;
			default:
				error("unexpected letter in ", s);
				break;
			}
			++words[s.substr(0, s.size() - 3)];
		}
		else
			++words[s];
	}

	for (auto p = words.begin(); p != words.end(); ++p) {
		auto q = p;
		++q;
		while (q != words.end()) {
			if (q->first == p->first + "s" && p->first.size() > 1)
				q = words.erase(q);
			else
				++q;
		}
	}
}

int main()
try {
	string iname;
	cin >> iname;
	ifstream ifs{ iname };

	map<string, int> words;
	clean_txt(words, ifs);
	for (auto x : words)
		cout << x.first << '\t' << x.second << '\n';

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}