#include "../../std_lib_facilities.h"

int main()
try {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname, ios_base::binary };
	if (!ifs)
		error("can't open input file ", iname);

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs)
		error("can't open output file ", oname);

	vector<char> v;

	for (char x; ifs.read(as_bytes(x), sizeof(char)); )
		v.push_back(x);

	for (char x : v)
		ofs << x;
	ofs.close();

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