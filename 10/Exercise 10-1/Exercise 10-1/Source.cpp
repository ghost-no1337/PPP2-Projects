#include "../../std_lib_facilities.h"

void get_number(ifstream &its, vector<double> &numbers)
{
	while (true) {
		double d;
		its >> d;
		if (its.bad() || its.fail())
			error("can't get numbers");
		numbers.push_back(d);
		if (its.eof())
			return;
	}
}

double get_sum(const vector<double> &numbers)
{
	double sum = 0;
	for (double d : numbers)
		sum += d;
	return sum;
}

int main()
try {
	vector<double> numbers;
	
	cout << "Please enter the file that contains numbers: ";
	string name;
	cin >> name;
	ifstream its{ name };
	if (!its)
		error("can't open the file ", name);

	get_number(its, numbers);
	double sum = get_sum(numbers);

	cout << "The sum of the numbers in the file " << name << " is " << sum << '\n';
	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "error:unknown error\n";
	keep_window_open("~~");
	return -1;
}