#include "../../std_lib_facilities.h"

struct Token
{
	int smallest_int;
	int largest_int;
	string smallest_string;
	string largest_string;
	vector<string> smallest_vector;
	vector<string> largest_vector;
};

void print_int(const vector<int>& v)
{
	for (int i : v)
		cout << i << ", \n";
}

void print_string(const vector<string>& v)
{
	for (string s : v)
		cout << s << ", \n";
}

void get_vector(vector<string> &v)
{
	for (string s; cin >> s; ) {
		if (s == "stop")
			return;
		v.push_back(s);
	}
}

Token find_int(vector<int> v)
{
	Token t;
	sort(v);

	t.smallest_int = v[0];
	t.largest_int = v[v.size() - 1];

	return t;
}

Token find_string(vector<string> v)
{
	Token t;
	sort(v);

	t.smallest_string = v[0];
	t.largest_string = v[v.size() - 1];

	return t;
}

vector<int> string_size(const vector<string> &v)
{
	vector<int> result;
	for (string s : v)
		result.push_back(s.size());
	return result;
}

Token string_size_compare(const vector<string> &v)
{
	Token t;
	
	vector<int> size = string_size(v);
	Token size_result = find_int(size);

	for (int i = 0; i < size.size(); ++i) {
		if (size[i] == size_result.smallest_int)
			t.smallest_vector.push_back(v[i]);
		if (size[i] == size_result.largest_int)
			t.largest_vector.push_back(v[i]);
	}

	return t;
}

int main()
{
	vector<string> test;
	get_vector(test);

	vector<int> size = string_size(test);
	cout << "The size of the strings are: \n";
	print_int(size);

	Token string_compare = string_size_compare(test);
	cout << "The shartest strings are: \n";
	print_string(string_compare.smallest_vector);
	cout << "The longest strings are: \n";
	print_string(string_compare.largest_vector);

	Token find_string_result = find_string(test);
	cout << "The first string is: " << find_string_result.smallest_string << '\n'
		<< "The last string is: " << find_string_result.largest_string << '\n';
	
	keep_window_open("~~");
	return 0;
}