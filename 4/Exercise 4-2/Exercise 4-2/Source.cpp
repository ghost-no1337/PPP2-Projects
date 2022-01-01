#include "../../std_lib_facilities.h"

int main()
{
	vector<double> temps;
	for (double temp; cin >> temp; )
		temps.push_back(temp);

	double sum = 0;
	for (double x : temps) 
		sum += x;
	cout << "Average temperature: " << sum / temps.size() << ".\n";

	sort(temps);
	if (temps.size() % 2 == 1)
		cout << "Medium temperature: " << (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2 << ".\n";
	else
		cout << "Medium temperature: " << temps[temps.size() / 2] << ".\n";

	keep_window_open();
	return 0;
}