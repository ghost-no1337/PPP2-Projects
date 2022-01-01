#include "../../std_lib_facilities.h"

void make_test(const string& lab, int n, int base, int spread)
{
	cout << "{ " << lab << " " << n << " { ";
	vector<int> v;
	int elem = base;
	for (int i = 0; i < n; ++i) {
		elem += randint(spread);
		v.push_back(elem);
	}

	sort(v);

	int val = base + randint(elem - base);
	bool found = false;
	for (int i : v) {
		if (i == val)
			found = true;
		cout << v[i] << " ";
	}
	cout << "} " << found << " }\n";
}

int main()
try {
	int no_of_test = 0;
	string lab = "rand_test_";

	++no_of_test;
	make_test(lab + to_string(no_of_test), randint(10000), 0, 100);

	for (int i = 0; i < 10; ++i) {
		++no_of_test;
		make_test(lab + to_string(i), randint(500), 0, randint(50));
	}
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