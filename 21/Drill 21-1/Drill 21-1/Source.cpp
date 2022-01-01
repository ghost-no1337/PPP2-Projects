#include "../../std_lib_facilities.h"

struct Item {
	string name;
	int iid;
	double value;
};

ostream& operator<<(ostream& os, const Item& it)
{
	return os << "{ " << it.name << ", " << it.iid << ", " << it.value << " }";
}

istream& operator>>(istream& is, Item& it)
{
	char ch1, ch2, ch3, ch4;

	is >> ch1 >> it.name >> ch2 >> it.iid >> ch3 >> it.value >> ch4;
	if (ch1 != '{' || ch2 != ',' || ch3 != ',' || ch4 != '}')
		is.clear(ios_base::badbit);
	return is;
}

int main()
{
	string fname;
	cin >> fname;
	ifstream ifs{ fname };

	istream_iterator<Item> is{ ifs };
	istream_iterator<Item> eof;

	vector<Item> vi{ is, eof };
	sort(vi.begin(), vi.end(), [](const Item& it1, const Item& it2) { return it1.name < it2.name; });
	sort(vi.begin(), vi.end(), [](const Item& it1, const Item& it2) { return it1.iid < it2.iid; });
	sort(vi.begin(), vi.end(), [](const Item& it1, const Item& it2) { return it1.value > it2.value; });

	vi.insert(vi.begin(), Item{ "horse shoe", 99, 12.34 });
	vi.insert(vi.begin(), Item{ "Canon S400", 9988, 499.95 });

	sort(vi.begin(), vi.end(), [](const Item& it1, const Item& it2) { return it1.name < it2.name; });
	vi.erase(vi.begin());
	vi.erase(vi.begin());

	sort(vi.begin(), vi.end(), [](const Item& it1, const Item& it2) { return it1.iid < it2.iid; });
	vi.erase(vi.begin());
	vi.erase(vi.begin());

	ostream_iterator<Item> os{ cout, "\n" };
	copy(vi.begin(), vi.end(), os);

	keep_window_open();
}