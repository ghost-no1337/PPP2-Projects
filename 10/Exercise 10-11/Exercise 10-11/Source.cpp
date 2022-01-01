#include "../../std_lib_facilities.h"

void get_int(ifstream &ist, vector<int> &v)
{
	while (true) {
		char ch;
		ist >> ch;
		if (ist.eof())
			return;
		else if (!ist)
			error("bad input");

		if (isdigit(ch)) {
			ist.unget();
			int i;
			ist >> i;
			v.push_back(i);
		}
	}
}

int get_sum(vector<int> &v)
{
	int sum = 0;
	for (int i : v)
		sum += i;
	return sum;
}

int main()
try {
	vector<int> file;

	cout << "Please enter the input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist)
		error("can't open input file");

	get_int(ist, file);
	int sum = get_sum(file);

	cout << "The sum of numbers in the file is " << sum << '\n';
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