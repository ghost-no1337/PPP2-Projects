#include "../../std_lib_facilities.h"

int main()
{
	double val1 = 0, val2 = 0;
	char exit = ' ';
	while (exit != '|') {
		cout << "Type two floating numbers:\n";
		cin >> val1 >> val2;

		if (val1 == val2)
			cout << "The numbers are equal.\n";
		else if (abs(val2 - val1) < 1.0 / 100)
				cout << "The numbers are almost equal.\n";
		
		cout << "Type '|' to exit. Type any character else to continue:\n";
		cin >> exit;
	}

	double smallest = 0, largest = 0;
	double val = 0;
	string unit = " ";
	exit = ' ';
	vector<double> vals;

	constexpr double cm_per_m = 100;
	constexpr double cm_per_in = 2.54;
	constexpr double in_per_ft = 12;

	while (exit != '|') {
		cout << "Type a length with a unit:\n";
		cin >> val >> unit;

		if (unit == "cm") {}
		else if (unit == "m")
			val *= cm_per_m;
		else if (unit == "in")
			val *= cm_per_in;
		else if (unit == "ft")
			val = val * in_per_ft * cm_per_in;
		else {
			simple_error("Not a unit I know");
		}

		vals.push_back(val);

		if (smallest == 0 || largest == 0) {
			smallest = val;
			largest = val;
		}
		else if (val < smallest) {
			cout << val << " cm is the smallest so far.\n";
			smallest = val;
		}
		else if (val > largest) {
			cout << val << " cm is the largest so far.\n";
			largest = val;
		}
		cout << "Type '|' to exit. Type any character else to continue:\n";
		cin >> exit;
	}
	cout << "\n\nHere is the results:\n";
	sort(vals);
	double sum = 0;
	for (int i = 0; i < vals.size(); ++i) {
		sum += vals[i];
		cout << vals[i] << '\n';
	}
	cout << "The smallest value is " << smallest << "cm.\n"
		<< "The largest value is " << largest << "cm.\n"
		<< "The number of the value is " << vals.size() << ".\n"
		<< "The sum of the value is " << sum << "cm.\n";
	
	keep_window_open();
	return 0;
}