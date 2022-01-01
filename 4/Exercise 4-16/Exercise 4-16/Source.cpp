#include "../../std_lib_facilities.h"

int mode(const vector<int>& vi)
{
	int appear_most = 0;
	int times = 0;

	int counter = 0;
	for (int i = 0; i < vi.size(); ++i) {
		for (int j = 0; j < vi.size(); ++j)
			if (vi[j] == vi[i])
				++counter;
		if (counter > times) {
			times = counter;
			appear_most = vi[i];
		}
		counter = 0;
	}

	return appear_most;
}

int main()
{
	vector<int> numbers;
	for (int number; cin >> number; ) {
		if (number <= 0)
			simple_error("positive numbers only");
		numbers.push_back(number);
	}

	sort(numbers);

	cout << "\nThe min of all the number is " << numbers[0] << ".\n"
		<< "The max of all the number is " << numbers[numbers.size() - 1] << ".\n"
		<< "The mode of all the number is " << mode(numbers) << ".\n";
	keep_window_open();
	return 0;
}