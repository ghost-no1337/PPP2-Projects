#include "../../std_lib_facilities.h"

template <typename Iter>
Iter find_last(Iter first, Iter last)
{
	auto s = first;
	for (auto p = first; p != last; ++p)
		if (*p >= *s)
			s = p;
	return s;
}

int main()
{
	vector<string> vs;
	string s;
	while (cin >> s && s != "!")
		vs.push_back(s);

	cout << *find_last(vs.begin(), vs.end()) << '\n';

	keep_window_open();
}