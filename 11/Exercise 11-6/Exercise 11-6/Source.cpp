#include "../../std_lib_facilities.h"

int main()
try {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist)
		error("can't open input file");

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ost{ oname };
	if (!ost)
		error("can't open output file");

	string lines;
	vector<string> dictionary_temp;
	vector<string> dictionary;

	// deal with punctuations:
	for (char ch; ist.get(ch); ) {
		switch (ch) {
		case '.': case ';': case',': case'?': case '\'':
			ch = ' ';
			break;
		case '\"':
		{
			ch = ' ';
			string temp;
			for (char c; ist.get(c);) {
				if (c == '\"')
					break;
				temp += c;
			}
			if (ist.eof())
				error("closing \" missing");
			dictionary_temp.push_back(temp);
			break;
		}
		default:
			if (isalpha(ch))
				ch = tolower(ch);
			break;
		}
		lines += ch;
	}

	// deal with '-'s:
	for (int i = 0; i < lines.size(); ++i) {
		switch (lines[i]) {
		case '-':
			if (i == 0 || i + 1 == lines.size()
				|| !(isalpha(lines[i - 1])) || !(isalpha(lines[i + 1])))
				lines[i] = ' ';
			break;
		default:
			break;
		}
	}

	// convert chars to strings:
	stringstream ss{ lines };
	for (string s; ss >> s; )
		dictionary_temp.push_back(s);

	// deal with "don't" and "can't":
	for (int i = 0; i < dictionary_temp.size(); ++i) {
		if (dictionary_temp[i] == "don" && i + 1 != dictionary_temp.size())
			if (dictionary_temp[i + 1] == "t") {
				dictionary_temp[i] = "do";
				dictionary_temp[i + 1] = "not";
			}
		else if (dictionary_temp[i] == "can" && i + 1 != dictionary_temp.size())
			if (dictionary_temp[i + 1] == "t") {
				dictionary_temp[i] = "cannot";
				dictionary_temp[i + 1] = "cannot";
			}
	}

	// deal with repeated words:
	for (int i = 0; i < dictionary_temp.size(); ++i) {
		if (i != 0 && dictionary_temp[i] == dictionary_temp[i - 1])
		{ }
		dictionary.push_back(dictionary_temp[i]);
	}

	sort(dictionary);
	for (string s : dictionary)
		ost << s << '\n';
	ost.close();
	cout << "Operation successful!\n";

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