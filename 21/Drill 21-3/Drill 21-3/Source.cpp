#include "../../std_lib_facilities.h"
#include <numeric>

int main()
{
	string fname;
	cin >> fname;
	ifstream ifs{ fname };

	istream_iterator<double> is{ ifs };
	istream_iterator<double> eof;

	vector<double> vd{ is, eof };

	ostream_iterator<double> os{ cout, "\n" };
	copy(vd.begin(), vd.end(), os);

	vector<int> vi{ vd.begin(), vd.end() };
	for (int i = 0; i < vd.size(); ++i)
		cout << "( " << vd[i] << ", " << vi[i] << " )\n";

	double sumd = 0.0;
	sumd = accumulate(vd.begin(), vd.end(), sumd);
	cout << sumd << '\n';

	int sumi = 0;
	sumi = accumulate(vi.begin(), vi.end(), sumi);
	cout << sumd - sumi << '\n';

	double mean = sumd / vd.size();
	cout << mean << '\n';

	vector<double> vd2;
	for (double d : vd)
		if (d < mean)
			vd2.push_back(d);
	copy(vd2.begin(), vd2.end(), os);

	sort(vd);
	copy(vd.begin(), vd.end(), os);

	keep_window_open();
}