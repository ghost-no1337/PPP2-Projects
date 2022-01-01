#include "../../std_lib_facilities.h"

vector<int> prime = { 2 };

bool is_prime(int i)
{
	for (int x : prime)
		if (i % x == 0)
			return false;
	return true;
}

int main()
{
	int max = 0;
	cout << "Type max: ";
	cin >> max;
	if (max < 2)
		simple_error("input number must be >= 2");

	for (int i = 2; i <= max; ++i)
		if (is_prime(i))
			prime.push_back(i);

	for (int i : prime)
		cout << i << '\n';

	keep_window_open();
	return 0;
}