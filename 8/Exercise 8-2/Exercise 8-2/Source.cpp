#include "../../std_lib_facilities.h"

void print(string label, const vector<int>& v)
{
	cout << "Label: " << label << '\n'
		<< "{ ";
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i + 1 != v.size())
			cout << ", ";
	}
	cout << " }";
}

void fibonacci(int x, int y, vector<int>& v, int n)
{	// x , y = start numbers; v = empty vector; n = numbers;
	if (x <= 0 || y <= 0)
		error("can't calculate fibonacci for negative numbers");
	v.push_back(x);
	v.push_back(y);

	if (n < 2)
		error("no enough numbers");

	for (int i = 2; i < n; ++i)
	{
		int temp = x;
		x = y;
		y += temp;
		v.push_back(y);
	}
}

int main()
try {
	vector<int> fibonacci_vector;
	fibonacci(1, 2, fibonacci_vector, 45);

	print("fibonacci", fibonacci_vector);
	cout << '\n';
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}