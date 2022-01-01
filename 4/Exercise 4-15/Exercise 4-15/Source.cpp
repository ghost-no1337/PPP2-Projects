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
	int range = 0;
	cout << "Type range: ";
	cin >> range;
	if (range <= 0)
		simple_error("range must be > 0");

	int i = 2;
	while (prime.size() < range) {
		if (is_prime(i))
			prime.push_back(i);
		++i;
	}

	for (int i : prime)
		cout << i << '\n';

	keep_window_open();
	return 0;
}