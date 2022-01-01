#include "../../std_lib_facilities.h"

struct Result
{
	double smallest;
	double largest;
	double mean;
	double median;
};

Result process(vector<double> v)
{
	Result result;

	sort(v);
	result.smallest = v[0];
	result.largest = v[v.size() - 1];

	double sum = 0;
	for (double d:v) {
		sum += d;
	}
	result.mean = sum / v.size();

	if (v.size() % 2 == 1)
		result.median = v[v.size() / 2];
	if (v.size() % 2 == 0)
		result.median = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;

	return result;
}

int main()
{
	vector<double> test;
	for (double d; cin >> d; )
		test.push_back(d);

	Result result = process(test);
	cout << "Smallest: " << result.smallest << '\n'
		<< "Largest: " << result.largest << '\n'
		<< "Mean: " << result.mean << '\n'
		<< "Median: " << result.median << '\n';

	keep_window_open("~~");
	return 0;
}