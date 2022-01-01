#include "../../std_lib_facilities.h"

template <typename T>
struct unique_ptr
{
	unique_ptr(T* p)
		:ptr{p} { }
	~unique_ptr() {	delete[] ptr; }
	T operator*() const { return *ptr; }
	T* operator->() const { return ptr; }
	T* release() {
		T* temp = ptr;
		ptr = nullptr;
		return temp;
	}

	unique_ptr& operator=(const unique_ptr&) = delete;
private:
	T* ptr;
};

int main()
{
	unique_ptr<vector<int>> p{ new vector<int> };
	p->push_back(1);
	p->push_back(2);
	p->push_back(3);
	p->push_back(4);
	p->push_back(5);

	for (int i : *p)
		cout << i << '\n';

	keep_window_open();
}