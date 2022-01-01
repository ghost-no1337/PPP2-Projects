#include "../../std_lib_facilities.h"

void get_text(ifstream &ist, vector<string> &v)
{
	while (true) {
		string s;
		ist >> s;
		if (ist.eof())
			return;
		else if (!ist)
			error("bad input");
		v.push_back(s);
	}
}

void print_text(ofstream &ost, const vector<string> &v)
{
	for (string s : v)
		ost << s << '\n';
}

int main()
try {
	cout << "Please enter input file name 1: ";
	string iname1;
	cin >> iname1;
	ifstream ist1{ iname1 };
	if (!ist1)
		error("can't open input file ", iname1);

	cout << "Please enter input file name 2: ";
	string iname2;
	cin >> iname2;
	ifstream ist2{ iname2 };
	if (!ist2)
		error("can't open input file ", iname2);

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ost{ oname };
	if (!ost)
		error("can't open input file ", oname);

	vector<string> file;

	get_text(ist1, file);
	get_text(ist2, file);

	sort(file);

	print_text(ost, file);
	ost.close();
	cout << "Operation successful.\n";

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