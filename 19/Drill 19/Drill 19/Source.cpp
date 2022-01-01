#include "../../std_lib_facilities.h"

template<typename T>
struct S
{
	S(T t)
		:val{ t } { }
	T& get();
	const T get() const;
	void operator=(const T& t);
private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T S<T>::get() const
{
	return val;
}

template<typename T>
void S<T>::operator=(const T& t)
{
	val = t;
}

template<typename T>
void read_val(S<T>& s)
{
	T t;
	cin >> t;
	s.get() = t;
}

template<typename T>
istream& operator<<(istream& is, vector<T> &vt)
{
	string s;
	is.get_line(s);
	istringstream iss{ s };

	T t;
	while (iss >> t)
		vt.push_back(t);

	return is;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &vt)
{
	os << "{ ";
	for (int i = 0; i < vt.size(); ++i) {
		os << vt[i];
		if (i != vt.size() - 1)
			os << ", ";
	}
	os << " }";
	return os;
}

int main()
{
	S<int> si{ 0 };
	read_val(si);
	S<char> sch{ 0 };
	read_val(sch);
	S<double> sd{ 0 };
	read_val(sd);
	S<string> ss{ "" };
	read_val(ss);
	S<vector<int> >svi{ { 1, 2, 3, 4, 5 } };

	cout << si.get() << '\n'
		<< sch.get() << '\n'
		<< sd.get() << '\n'
		<< ss.get() << '\n'
		<< svi.get()[0] << '\n';

	keep_window_open();
}