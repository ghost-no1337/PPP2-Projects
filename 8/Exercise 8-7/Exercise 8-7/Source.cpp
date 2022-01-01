#include "../../std_lib_facilities.h"

void print(const vector<string> &name, const vector<int> &age)
{
	cout << '\n';
	for (int i = 0; i < name.size(); ++i)
		cout << name[i] << '\t' << age[i] << ", \n";
}

void load_age(vector<string> &name, vector<int> &age)
{
	string name_string;
	int age_int = 0;

	while (true) {
		cout << "Name: ";
		cin >> name_string;
		if (name_string == "NoName")
			return;
		for (string s : name)
			if (name_string == s)
				error("repeated name");
		name.push_back(name_string);
		cout << "Age of " << name_string << ": ";
		cin >> age_int;
		age.push_back(age_int);
	}
}

void sort_name(vector<string> &name, vector<int> &age)
{
	vector<string> name_copy = name;
	vector<int> age_copy = age;
	sort(name);

	for (int i = 0; i < name.size(); ++i)
		for (int j = 0; j < name_copy.size(); ++j)
			if (name[i] == name_copy[j])
				age[i] = age_copy[j];
}

int main()
try {
	vector<string> name;
	vector<int> age;

	load_age(name, age);
	print(name, age);

	sort_name(name, age);
	print(name, age);

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr<< "error: unknown error\n";
	keep_window_open();
	return -1;
}