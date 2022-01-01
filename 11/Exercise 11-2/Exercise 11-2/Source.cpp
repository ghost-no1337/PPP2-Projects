#include "../../std_lib_facilities.h"

bool check(string line, string word)
{
	stringstream ss{ line };
	vector<string> words;

	for (string s; ss >> s; )
		words.push_back(s);

	for (string s : words)
		if (s == word)
			return true;
	return false;
}

int main()
try {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist)
		error("can't open input file ", iname);

	cout << "Please enter the word for search: ";
	string word;
	cin >> word;

	vector<string> lines;
	
	while (true) {
		string s;
		getline(ist, s);
		if (ist)
			lines.push_back(s);
		if (ist.eof())
			break;
	}
	//works properly till here.

	for (int i = 0; i < lines.size(); ++i) {
		if (check(lines[i], word))
			cout << lines[i] << "\tLine number: " << i + 1 << '\n';
	}

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open("~~");
	return -1;
}