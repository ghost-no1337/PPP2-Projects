#include "../../std_lib_facilities.h"

int main()
try {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		error("can't open input file");

	cout << "Please enter output file name: ";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs)
		error("can't open output file");

	vector<double> numbers;

	for (double d; ifs >> d;)
		numbers.push_back(d);

	for (int i = 0; i < numbers.size(); ++i) {
		ofs << scientific << setprecision(8) << setw(20) << numbers[i];
		if ((i + 1) % 4 == 0)
			ofs << '\n';
	}
	ofs.close();
	cout << "Operation Successful!";

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