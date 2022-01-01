#include "../../std_lib_facilities.h"
#include <type_traits>

template<typename T, typename U>
typename common_type<T, U>::type f(vector<T> vt, vector<U> vu)
{
	typename common_type<T, U>::type sum = typename common_type<T, U>::type();
	if (vt.size() <= vu.size())
		for (int i = 0; i < vt.size(); ++i)
			sum += vt[i] * vu[i];
	else
		for (int i = 0; i < vu.size(); ++i)
			sum += vt[i] * vu[i];

	return sum;
}

int main()
{
	vector<int> vi{ 1, 2, 3, 4, 5 };
	vector<double> vd{ 1.1, 1.2, 1.3, 1.4, 1.5 };

	cout << f(vd, vi) << '\n';

	keep_window_open();
}