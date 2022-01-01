#include <memory>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <Windows.h>

using namespace std;

#define _SCL_SECURE_NO_WARNINGS

template <typename T, typename A = allocator<T>>
class Vector {
	A alloc;
	int sz;
	T* elem;
	int space;
public:
	Vector()
		:sz{ 0 }, elem{ nullptr }, space{ 0 } { }
	explicit Vector(int s)
		:sz{ s }, elem{ new T[s] }, space{ s }
	{
		for (int i = 0; i < sz; ++i) elem[i] = 0;
	}
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	Vector(Vector&&);
	Vector& operator=(Vector&&);
	~Vector() { delete[] elem; }
	T& operator[](int n) { return elem[n]; }
	const T& operator[](int n) const { return elem[n]; }
	int size() const { return sz; }
	int capacity() const { return space; }
	void resize(int newsize);
	void push_back(const T& d);
	void reserve(int newalloc);
};

template <typename T, typename A>
Vector<T, A>::Vector(const Vector& a)
	:sz{ a.sz }, elem{ new T[a.sz] }
{
	copy(a.elem, a.elem + a.sz, elem);
}

template <typename T, typename A>
Vector<T, A>& Vector<T, A>::operator=(const Vector& a)
{
	T* p = new T[a.sz];
	copy(a.elem, a.elem + a.sz, elem);
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

template <typename T, typename A>
Vector<T, A>::Vector(Vector&& a)
	:sz{ a.sz }, elem{ a.elem }
{
	a.sz = 0;
	a.elem = nullptr;
}

template <typename T, typename A>
Vector<T, A>& Vector<T, A>::operator=(Vector&& a)
{
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	a.elem = nullptr;
	a.sz = 0;
	return *this;
}

template<typename T, typename A>
void Vector<T, A>::reserve(int newalloc)
{
	if (newalloc <= space) 
		return;
	T* p = alloc.allocate(newalloc);
	for (int i = 0; i < sz; ++i)
		alloc.construct(&p[i], elem[i]);
	for (int i = 0; i < sz; ++i)
		alloc.destroy(&elem[i]);
	alloc.deallocate(elem, space);
	elem = p;
	space = newalloc;
}

template <typename T, typename A>
void Vector<T, A>::resize(int newsize)
{
	reserve(newsize);
	for (int i = sz; i < newsize; ++i)
		elem[i] = 0;
	sz = newsize;
}

template <typename T, typename A>
void Vector<T, A>::push_back(const T& d)
{
	if (space == 0)
		reserve(8);
	else if (sz == space)
		reserve(2 * space);
	elem[sz] = d;
	++sz;
}

int main()
{
	Vector<double> vd1;
	for (double d = 0; cin >> d; )
		vd1.push_back(d);
	for (int i = 0; i < vd1.size(); ++i)
		cout << vd1[i] << '\n';

	Vector<double> vd2 = vd1;
	for (double d = 0; cin >> d; )
		vd2.push_back(d);
	vd1 = vd2;
	for (int i = 0; i < vd1.size(); ++i)
		cout << vd1[i] << '\n';

	char ch; cin >> ch;
	return 0;
}