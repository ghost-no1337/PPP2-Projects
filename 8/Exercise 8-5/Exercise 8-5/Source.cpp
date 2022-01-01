#include "../../std_lib_facilities.h"

void print(const vector<int>& v)
{
	for (int i : v)
		cout << i << ", \n";
}

vector<int> reserve1(const vector<int>& v)
{
	vector<int> new_vector(v.size());

	for (int i = 0; i < v.size(); ++i)
		new_vector[new_vector.size() - 1 - i] = v[i];

	return new_vector;
}

void reserve2(vector<int>& v)
{
	for (int i = 0; i < v.size() / 2; ++i)
		swap(v[i], v[v.size() - 1 - i]);
}

int main()
{
	vector<int> original_vector{ 1, 3, 5, 7, 9 };

	// Way 1
	cout << "Way 1:\n";
	vector<int> new_vector = reserve1(original_vector);
	print(original_vector);
	cout << '\n';
	print(new_vector);

	// Way 2
	cout << "\nWay 2:\n";
	reserve2(original_vector);
	print(original_vector);

	keep_window_open();
}