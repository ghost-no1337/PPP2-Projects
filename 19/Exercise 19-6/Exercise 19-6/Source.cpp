#include "../../std_lib_facilities.h"

template<typename T>
struct Number {
	Number(T t)
		:val{ t } { }
	T val;
};

template<typename T, typename U>
Number<T> operator+(const Number<T> &nt, const Number<U> &nu)
{
	return Number<T>{ nt.val + nu.val };
}

template<typename T, typename U>
Number<T> operator-(const Number<T> &nt, const Number<U> &nu)
{
	return Number<T>{ nt.val - nu.val };
}

template<typename T, typename U>
Number<T> operator*(const Number<T> &nt, const Number<U> &nu)
{
	return Number<T>{ nt.val * nu.val };
}

template<typename T, typename U>
Number<T> operator/(const Number<T> &nt, const Number<U> &nu)
{
	return Number<T>{ nt.val / nu.val };
}

template<typename T, typename U>
Number<T> operator%(const Number<T> &nt, const Number<U> &nu)
{
	return Number<T>{ nt.val % nu.val };
}

int main()
try {
	int i = 0;
	double d = 0;
	cin >> i >> d;
	Number<int> ni{ i };
	Number<double> nd{ d };

	Number<double> v1 = nd + ni;
	Number<double> v2 = nd - ni;
	Number<double> v3 = nd * ni;
	Number<double> v4 = nd / ni;
	// Number<double> v5 = nd % ni;

	cout << v1.val << '\n'
		<< v2.val << '\n'
		<< v3.val << '\n'
		<< v4.val << '\n';
	// cout << v5.val << '\n';

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}