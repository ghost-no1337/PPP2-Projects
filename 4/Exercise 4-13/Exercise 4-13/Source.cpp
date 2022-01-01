#include "../../std_lib_facilities.h"

int main()
{
	int max = 0;
	cout << "Type max: ";
	cin >> max;
	if (max < 2)
		simple_error("input number must be >= 2");
	
	vector<int> prime(max + 1);
	prime[0] = 0;
	prime[1] = 0;
	for (int i = 2; i <= max; ++i)
		prime[i] = i;
	for (int i = 0; i < prime.size(); ++i)
		if (prime[i] != 0)
			for (int j = i + i; j < prime.size(); ++j)
				if (prime[j] % i == 0)
					prime[j] = 0;

	for (int i : prime)
		if (i != 0)
			cout << i << '\n';

	keep_window_open();
	return 0;
}