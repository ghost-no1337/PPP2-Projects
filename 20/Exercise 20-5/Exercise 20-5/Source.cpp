#include "../../std_lib_facilities.h"

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vt)
{
	os << "{ ";
	for (auto p = vt.begin(); p != vt.end(); ++p)
		if (vt.end() - p == 1)
			os << *p;
		else
			os << *p << ", ";
	os << " }";
	return os;
}

template <typename T>
istream& operator>>(istream& is, vector<T>& vt)
{
	char ch;
	is >> ch;
	if (ch != '{') {
		is.clear(ios_base::badbit);
		return is;
	}

	T t;
	while (is >> t >> ch) {
		vt.push_back(t);
		if (ch == '}')
			return is;
		else if (ch != ',') {
			is.clear(ios_base::badbit);
			return is;
		}
	}
}

int main()
{
	vector<int> vi;
	cin >> vi;
	cout << vi << '\n';

	keep_window_open();
}