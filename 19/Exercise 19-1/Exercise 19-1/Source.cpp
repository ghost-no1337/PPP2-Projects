#include "../../std_lib_facilities.h"

template<typename T>
void f(vector<T> &v1, vector<T> &v2)
{
	if (v1.size() <= v2.size())
		for (int i = 0; i < v1.size(); ++i)
			v1[i] += v2[i];
	else
		for (int i = 0; i < v2.size(); ++i)
			v1[i] += v2[i];
}

int main()
{
	vector<int> v1{ 1, 2, 3, 4, 5 };
	vector<int> v2{ 1, 2, 3, 4, 5 };
	f(v1, v2);
	for (int i : v1)
		cout << i << '\n';

	vector<char> v3{ 'A', 'B', 'C', 'D' };
	vector<char> v4{ '0', '1', '2', '3', '4', '5' };
	f(v3, v4);
	for (char ch : v3)
		cout << ch << '\n';

	keep_window_open();
}