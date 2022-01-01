#include "../../std_lib_facilities.h"

vector<int> Monday;
vector<int> Tuesday;
vector<int> Wednesday;
vector<int> Thursday;
vector<int> Friday;
vector<int> Saturday;
vector<int> Sunday;

int sum(const vector<int>& x)
{
	int sum = 0;
	for (int i : x)
		sum += i;
	return sum;
}

int main()
try {
	cout << "Type day of the week and a value:\n";
	string day;
	int value = 0;

	while (cin >> day >> value)
	{
		if (day == "Monday" || day == "Mon" || day == "monday")
			Monday.push_back(value);
		else if (day == "Tuesday" || day == "Tue" || day == "tuesday")
			Tuesday.push_back(value);
		else if (day == "Wednesday" || day == "Wed" || day == "wednesday")
			Wednesday.push_back(value);
		else if (day == "Thursday" || day == "Thu" || day == "thursday")
			Thursday.push_back(value);
		else if (day == "Friday" || day == "Fri" || day == "friday")
			Friday.push_back(value);
		else if (day == "Saturday" || day == "Sat" || day == "saturday")
			Saturday.push_back(value);
		else if (day == "Sunday" || day == "Sun" || day == "sunday")
			Sunday.push_back(value);
	}

	cout << "Monday sum: " << sum(Monday) << '\n'
		<< "Tuesday sum: " << sum(Tuesday) << '\n'
		<< "Wednesday sum: " << sum(Wednesday) << '\n'
		<< "Thursday sum: " << sum(Thursday) << '\n'
		<< "Friday sum: " << sum(Friday) << '\n'
		<< "Saturday sum: " << sum(Saturday) << '\n'
		<< "Sunday sum: " << sum(Sunday) << '\n';

	keep_window_open("~~");
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error.\n";
	keep_window_open();
	return -1;
}