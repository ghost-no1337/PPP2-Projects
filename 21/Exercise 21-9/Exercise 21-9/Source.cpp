#include "../../std_lib_facilities.h"

struct Purchase {
	string name;
	int unit_price;
	int count;
};

struct Order {
    string name;
    string address;
    vector<Purchase> purchases;
};

ostream& operator<<(ostream& os, const Purchase& p)
{
	return os << "{ " << p.name << ", " << p.unit_price << ", " << p.count << " }";
}

istream& operator>>(istream& is, Purchase& p)
{
	char ch1, ch2, ch3, ch4;
	if (is >> ch1 >> p.name >> ch2 >> p.unit_price >> ch3 >> p.count >> ch4)
		if (ch1 != '{' || ch2 != ',' || ch3 != ',' || ch4 != '}') {
			is.clear(ios_base::badbit);
			return is;
		}
	return is;
}

ostream& operator<<(ostream& os, const Order& o)
{
	os << "{ " << o.name << ", " << o.address << ", ";
	for (int i = 0; i < o.purchases.size(); ++i) {
		os << o.purchases[i];
		if (i + 1 != o.purchases.size())
			os << ", ";
		else os << " }";
	}
	return os;
}

istream& operator>>(istream& is, Order& o)
{
	char ch1, ch2, ch3, ch4;
	if (is >> ch1 >> o.name >> ch2 >> o.address >> ch3) {
		if (ch1 != '{' || ch2 != ',' || ch3 != ',') {
			is.clear(ios_base::badbit);
			return is;
		}
		for (Purchase p; is >> p >> ch4;) {
			o.purchases.push_back(p);
			if (ch4 == '}')
				break;
			else
				is.putback(ch4);
		}
	}
	return is;
}

bool Name_comparison(Order& o1, Order& o2)
{
	return o1.name < o2.name;
}

bool Address_comparison(Order& o1, Order& o2)
{
	return o1.address < o2.address;
}

template <typename Iter>
int calculate_sum(Iter first, Iter last)
{
	int sum = 0;
	for (auto p = first; p != last; ++p)
		for (int i = 0; i < p->purchases.size(); ++i)
			sum += p->purchases[i].unit_price * p->purchases[i].count;
	return sum;
}

int main()
{
	string iname1, oname1, iname2, oname2, oname3;
	cin >> iname1 >> oname1 >> iname2 >> oname2 >> oname3;

	ifstream ifs1{ iname1 };
	ifstream ifs2{ iname2 };
	istream_iterator<Order> is1{ ifs1 };
	istream_iterator<Order> is2{ ifs2 };
	istream_iterator<Order> eof;

	ofstream ofs1{ oname1 };
	ofstream ofs2{ oname2 };
	ofstream ofs3{ oname3 };
	ostream_iterator<Order> os1{ ofs1, "\n" };
	ostream_iterator<Order> os2{ ofs2, "\n" };
	ostream_iterator<Order> os3{ ofs3, "\n" };

	vector<Order> vo{ is1, eof };
	sort(vo, Name_comparison);
	copy(vo.begin(), vo.end(), os1);

	list<Order> lo{ is2, eof };
	lo.sort(Address_comparison);
	copy(lo.begin(), lo.end(), os2);

	merge(vo.begin(), vo.end(), lo.begin(), lo.end(), os3, Name_comparison);

	int sum = calculate_sum(vo.begin(), vo.end());
	sum += calculate_sum(lo.begin(), lo.end());
	cout << sum << '\n';

	keep_window_open();
}