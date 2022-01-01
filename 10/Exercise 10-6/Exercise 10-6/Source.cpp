#include "../../std_lib_facilities.h"

class Roman_int
{
public:
	int I = 0;
	int V = 0;
	int X = 0;
	int L = 0;
	int C = 0;
	int D = 0;
	int M = 0;
	int as_int() const;
};

int Roman_int::as_int() const
{
	return 1 * I + 5 * V + 10 * X + 50 * L + 100 * C + 500 * D + 1000 * M;
}

istream &operator >> (istream &is, Roman_int &r)
{
	string temp;
	is >> temp;
	for (int i = 0; i < temp.size(); ++i) {
		switch (temp[i]) {
		case 'M':
			++r.M;
			break;
		case 'D':
			++r.D;
			break;
		case 'C':
			if (i != temp.size() && (temp[i + 1] == 'M' || temp[i+1] == 'D'))
				--r.C;
			else
				++r.C;
			break;
		case 'L':
			++r.L;
			break;
		case 'X':
			if (i != temp.size() && (temp[i + 1] == 'C' || temp[i + 1] == 'L'))
				--r.X;
			else
				++r.X;
			break;
		case 'V':
			++r.V;
			break;
		case 'I':
			if (i != temp.size() && (temp[i + 1] == 'X' || temp[i + 1] == 'V'))
				--r.I;
			else
				++r.I;
			break;
		}
	}
	if (r.as_int() <= 0 || r.as_int() >= 4000)
		error("input out of range");
	return is;
}

ostream &operator << (ostream &os, const Roman_int &r)
{
	int temp = r.as_int();
	while (true) {
		if (temp >= 1000) {
			os << 'M';
			temp -= 1000;
		}
		else if (temp >= 900) {
			os << "CM";
			temp -= 900;
		}
		else if (temp >= 500) {
			os << 'D';
			temp -= 500;
		}
		else if (temp >= 400) {
			os << "CD";
			temp -= 400;
		}
		else if (temp >= 100) {
			os << 'C';
			temp -= 100;
		}
		else if (temp >= 90) {
			os << "XC";
			temp -= 90;
		}
		else if (temp >= 50) {
			os << 'L';
			temp -= 50;
		}
		else if (temp >= 40) {
			os << "XL";
			temp -= 40;
		}
		else if (temp >= 10) {
			os << 'X';
			temp -= 10;
		}
		else if (temp >= 9) {
			os << "IX";
			temp -= 9;
		}
		else if (temp >= 5) {
			os << 'V';
			temp -= 5;
		}
		else if (temp >= 4) {
			os << "IV";
			temp -= 4;
		}
		else if (temp >= 1) {
			os << 'I';
			temp -= 1;
		}
		else
			return os;
	}
}

int main()
try {
	cout << "Type a Roman int: ";
	Roman_int r;
	cin >> r;
	cout << "Roman " << r << " equals " << r.as_int() << '\n';

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch(...) {
	cerr << "error: unknown error\n";
	keep_window_open("~~");
	return -1;
}