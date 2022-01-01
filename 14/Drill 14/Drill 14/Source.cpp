#include "../../std_lib_facilities.h"

struct B1
{
	virtual void vf() { cout << "B1::vf()\n"; }
	void f() { cout << "B1::f()\n"; }
	virtual void pvf() = 0 { cout << "B1::pvf()\n"; };
};

struct D1 : B1
{
	void vf() { cout << "D1::vf()\n"; }
	void f() { cout << "D1::f()\n"; }
};

struct D2 : D1
{
	void pvf() { cout << "D2::pvf()\n"; }
};

struct B2
{
	virtual void pvf() = 0 { cout << "B2::pvf()\n"; }
};

struct D21 : B2
{
	void pvf() { cout << "D21::pvf(), " << s << '\n'; }
	string s = "string";
};

struct D22 : B2
{
	void pvf() { cout << "D22::pvf(), " << i << '\n'; }
	int i = 0;
};

void f(B2 &b2)
{
	b2.pvf();
}

int main()
{
	//B1 b1;
	//b1.vf();
	//b1.f();
	//b1.pvf();

	//D1 d1;
	//d1.vf();
	//d1.f();

	//B1 &b1r = d1;
	//b1r.vf();
	//b1r.f();

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	D21 d21;
	f(d21);

	D22 d22;
	f(d22);

	keep_window_open();
	return 0;
}