#include "../../std_lib_facilities.h"

int main()
try {
	cout << "Please enter the input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist)
		error("can't open input file, ", iname);

	cout << "Please enter the output file name: ";
	string oname;
	cin >> oname;
	ofstream ost{ oname };
	if (!ost)
		error("can't open output file, ", iname);

	vector<char> v;

	char ch;
	while (ist.get(ch)) {
		if (isalpha(ch))
			ch = tolower(ch);
		v.push_back(ch);
	}

	for (char ch : v)
		ost << ch;
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