#include "../../std_lib_facilities.h"

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
	Iterator high = first;
	for (Iterator p = first; p != last; ++p)
		if (*high < *p) high = p;
	return high;
}

double* get_from_jack(int* count);

vector<double>* get_from_jill();

void fct()
{
	int jack_count = 20;
	double* jack_data = get_from_jack(&jack_count);
	vector<double>* jill_data = get_from_jill();

	double* jack_high = high(jack_data, jack_data + jack_count);
	vector<double>& v = *jill_data;
	double* jill_high = high(&v[0], &v[0] + v.size());
	cout << "Jill's high " << *jill_high << "; Jack's high " << *jack_high;

	delete[] jack_data;
	delete jill_data;
}

double* get_from_jack(int* count)
{
	cout << "Please enter Jack's file name: ";
	string jack_name;
	cin >> jack_name;
	ifstream ifs{ jack_name };
	if (!ifs)
		error("can't open ", jack_name);

	double* arr = new double[*count];
	double d;
	int index = 0;
	while (ifs >> d) {
		arr[index] = d;
		++index;
	}
	return arr;
}

vector<double>* get_from_jill()
{
	cout << "Please enter Jill's file name: ";
	string jill_name;
	cin >> jill_name;
	ifstream ifs{ jill_name };
	if (!ifs)
		error("can't open ", jill_name);

	vector<double>* vec = new vector<double>;
	double d;
	while (ifs >> d)
		vec->push_back(d);
	return vec;
}

int main()
{
	fct();

	cout << '\n';
	keep_window_open();
}