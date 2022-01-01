#include "../../std_lib_facilities.h"

template <typename Iter>
void print(Iter begin, Iter end)
{
	cout << "{ ";
	for (auto p = begin; p != end; ++p) {
		cout << *p << ' ';
	}
	cout << "}\n";
}

template <typename Iter1, typename Iter2>
Iter2 self_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (auto p = f1; p != e1; ++p) {
		*f2 = *p;
		++f2;
	}
	return f2;
}

int main()
{
	int a1[]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> l1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int a2[10];
	for (int i = 0; i < 10; ++i)
		a2[i] = a1[i];
	vector<int> v2 = v1;
	list<int> l2 = l1;

	for (int i = 0; i < 10; ++i)
		a1[i] += 2;
	for (int i = 0; i < v1.size(); ++i)
		v1[i] += 3;
	for (auto p = l1.begin(); p != l1.end(); ++p)
		*p += 5;

	self_copy(&a1[0], &a1[10], v1.begin());
	self_copy(l1.begin(), l1.end(), &a1[0]);

	print(&a1[0], &a1[10]);
	print(v1.begin(), v1.end());
	print(l1.begin(), l1.end());

	keep_window_open();
}