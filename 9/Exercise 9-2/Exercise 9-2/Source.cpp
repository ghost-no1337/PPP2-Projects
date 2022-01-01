#include "../../std_lib_facilities.h"

class Name_pairs
{
public:
	string name_vector(int i) const { return name[i]; }
	double age_vector(int i) const { return age[i]; }
	int name_size() const { return name.size(); }

	void read_names();
	void read_ages();
	void sort_name();
private:
	vector<string> name;
	vector<double> age;
};

void Name_pairs::read_names()
{
	cout << "Please enter a series of names. Enter 'NoName' to quit.\n";
	string name_string;
	while (true)
	{
		cin >> name_string;
		if (name_string == "NoName")
			return;
		for (string s : name)
			if (name_string == s)
				error("repeated name");
		name.push_back(name_string);
	}
}

void Name_pairs::read_ages()
{
	
	for (string s : name) {
		cout << "Age of " << s << ": ";
		int age_int;
		cin >> age_int;
		if (age_int <= 0)
			error("negative ages");
		age.push_back(age_int);
	}
}

void Name_pairs::sort_name()
{
	vector<string> name_copy = name;
	vector<double> age_copy = age;
	sort(name);

	for (int i = 0; i < name.size(); ++i)
		for (int j = 0; j < name_copy.size(); ++j)
			if (name[i] == name_copy[j])
				age[i] = age_copy[j];
}

ostream& operator<< (ostream &os, const Name_pairs &np)
{
	for (int i = 0; i < np.name_size(); ++i)
		os << '(' << np.name_vector(i) << ", " << np.age_vector(i) << ")\n";
	return os;
}

bool operator== (const Name_pairs &np1, const Name_pairs &np2)
{
	if (np1.name_size() != np2.name_size())
		return false;
	for (int i = 0; i < np1.name_size(); ++i) {
		if (np1.name_vector(i) != np2.name_vector(i) || np1.age_vector(i) != np2.age_vector(i))
			return false;
	}
	return true;
}

bool operator!= (const Name_pairs &np1, const Name_pairs &np2)
{
	return !(np1 == np2);
}

int main()
try {
	Name_pairs np;
	
	np.read_names();
	np.read_ages();
	np.sort_name();
	
	cout << np << '\n';

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}