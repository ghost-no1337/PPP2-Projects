#include "../../std_lib_facilities.h"  

struct Reading 
{
	int hour;
	double temperature;
	char unit;
};

constexpr double kelvin_zero = -273.15;
void convert(double &temperature)
{	// temperature >= -273.15
	if (temperature < kelvin_zero)
		error("below absolute zero.");
	temperature = 9.0 / 5 * temperature + 32;
}

int main()
try {
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist) 
		error("can't open input file ", iname);

	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) 
		error("can't open output file ", oname);

	vector<Reading> temps;
	int hour;
	double temperature;
	char unit;
	while (ist >> hour >> temperature >> unit) {
		if (hour < 0 || hour > 23) 
			error("hour out of range");
		if (unit == 'c')
			convert(temperature);
		temps.push_back(Reading{ hour, temperature, unit });
	}

	for (int i = 0; i < temps.size(); ++i)
		ost << '(' << temps[i].hour << ','
		<< temps[i].temperature << ")\n";
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