#include "../../std_lib_facilities.h"
#include <map>

template <typename T, typename U>
void read(map<T, U>& mtu, istream& is)
{
	char ch1, ch2, ch3;
	T t;
	U u;
	while (is >> ch1 >> t >> ch2 >> u >> ch3) {
		if (ch1 != '{' || ch2 != ',' || ch3 != '}') {
			is.clear(ios_base::badbit);
			return;
		}
		mtu[t] = u;
	}
}

template <typename T, typename U>
void write(map<T, U>& mtu, ostream& os)
{
	for (auto x : mtu)
		os << "{ " << x.first << ", " << x.second << " }\n";
}

int main()
{
	map<string, int> msi;
	read(msi, cin);
	write(msi, cout);

	int sum = 0;
	for (auto x : msi)
		sum += x.second;
	cout << sum << '\n';

	map<int, string> mis;
	for (auto x : msi)
		mis[x.second] = x.first;
	write(mis, cout);

	keep_window_open("~~");
}