#include "../../std_lib_facilities.h"

void print(const vector<string>& v)
{
	for (string s : v)
		cout << s << ", \n";
}

vector<string> reserve1(const vector<string>& v)
{
	vector<string> new_vector(v.size());

	for (int i = 0; i < v.size(); ++i)
		new_vector[new_vector.size() - 1 - i] = v[i];

	return new_vector;
}

void reserve2(vector<string>& v)
{
	for (int i = 0; i < v.size() / 2; ++i)
		swap(v[i], v[v.size() - 1 - i]);
}

int main()
{
	vector<string> original_vector{ "1", "3", "5", "7", "9" };

	// Way 1
	cout << "Way 1:\n";
	vector<string> new_vector = reserve1(original_vector);
	print(original_vector);
	cout << '\n';
	print(new_vector);

	// Way 2
	cout << "\nWay 2:\n";
	reserve2(original_vector);
	print(original_vector);

	keep_window_open();
}