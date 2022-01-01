#include "../../std_lib_facilities.h"

int main()
try {
	vector<double> numbers;
	vector<double> differences;

	int N = 0;
	double sum = 0;
	cout << "Please enter the numbers of values you want to sum:\n";
	cin >> N;
	if (N <= 0)
		error("no negative numbers");
	cout << "Please enter some doubles (press '|' to stop):\n";
	for (double number; cin >> number; )
		numbers.push_back(number);
	if (N > numbers.size())
		error("not enough number in vector");

	cout << "The sum of the first " << N << " numbers ( ";
	for (int i = 0; i < N; ++i)	{
		sum += numbers[i];
		cout << numbers[i] << ' ';
		if (i != 0)	{
			differences.push_back(numbers[i] - numbers[i - 1]);
		}
	}
	cout << ") is " << sum << ".\n";

	cout << "The differences is listed as follow: \n";
	for (double x : differences)
		cout << x << ' ';
	cout << '\n';

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}