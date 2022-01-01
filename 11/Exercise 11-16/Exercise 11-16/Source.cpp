#include "../../std_lib_facilities.h"

int main()
try {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		error("can't open input file");

	vector<double> numbers;

	for (double d; ifs >> d;)
		numbers.push_back(d);

	sort(numbers);

	int counter = 1;
	for (int i = 0; i < numbers.size(); ++i) {
		if (i == 0)
		cout << numbers[i] << '\t';
		else if (numbers[i] == numbers[i - 1]) {
			++counter;
			if (i + 1 == numbers.size())
				cout << counter << '\n';
		}
		else {
			if (counter == 1)
				cout << '\n' << numbers[i] << '\t';
			else {
				cout << counter << '\n' << numbers[i] << '\t';
				counter = 1;
			}
		}
	}
	cout << '\n';

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