#include "../../std_lib_facilities.h"

void get_temps(ifstream &ist, vector<double> &temps)
{
	char ch1, ch2, ch3;
	int hour;
	double temperature;
	while (ist >> ch1 >> hour >> ch2 >> temperature >> ch3) {
		if (ch1 != '(' || ch2 != ',' || ch3 != ')')
			error("bad input format");
		temps.push_back(temperature);
	}
}

double mean(const vector<double> &v)
{
	double sum = 0;
	for (double d : v) {
		sum += d;
	}
	return sum / v.size();
}

double median(vector<double> v)
{
	sort(v);
	if (v.size() % 2 == 1)
		return v[v.size() / 2];
	if (v.size() % 2 == 0)
		return (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
}

int main()
try {
	vector<double> temps;
	
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist)
		error("can't open input file ", iname);

	get_temps(ist, temps);

	double mean_temps = mean(temps);
	double median_temps = median(temps);

	cout << "Mean: " << mean_temps << '\n'
		<< "Median: " << median_temps << '\n';

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