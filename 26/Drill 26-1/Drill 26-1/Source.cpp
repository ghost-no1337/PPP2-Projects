#include "../../std_lib_facilities.h"

struct Test {
	string label;
	int val;
	vector<int> seq;
	bool res;
};

istream& operator>>(istream& is, Test& t)
{
	char ch1, ch2;

	if (is >> ch1 >> t.label >> t.val >> ch2 && (ch1 != '{' || ch2 != '{')) {
		is.clear(ios_base::badbit);
		return is;
	}

	vector<int> temp{ istream_iterator<int>{ is }, istream_iterator<int>{} };

	t.seq = temp;

	char ch3, ch4;
	int res = 0;

	if (is >> ch3 >> res >> ch4 && (ch3 != '}' || ch4 != '}')) {
		is.clear(ios_base::badbit);
		return is;
	}

	t.res = res;

	return is;
}

int test_all(istream& is)
{
	int error_count = 0;
	for (Test t; is >> t; ) {
		bool r = binary_search(t.seq.begin(), t.seq.end(), t.val);
		if (r != t.res) {
			cout << "failure: test " << t.label
				<< " binary_search: "
				<< t.seq.size() << " elements, val==" << t.val
				<< " –> " << t.res << '\n';
			++error_count;
		}
	}
	return error_count;
}

int main()
{
	string iname;
	cin >> iname;
	int errors = test_all(ifstream{ iname });
	cout << "number of errors: " << errors << "\n";
	keep_window_open();
}
