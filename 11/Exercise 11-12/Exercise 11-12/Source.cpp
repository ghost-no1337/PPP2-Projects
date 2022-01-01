#include "../../std_lib_facilities.h"

int main()
try {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		error("can't open input file ", iname);

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs)
		error("can't open output file ", oname);

	vector<char> chars;

	for (char ch; ifs.get(ch); )
		chars.push_back(ch);

	for (int i = chars.size() - 1; i >= 0; --i)
		ofs << chars[i];
	ofs.close();
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