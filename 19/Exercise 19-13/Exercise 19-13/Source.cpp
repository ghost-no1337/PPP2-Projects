#include "../../std_lib_facilities.h"

struct Tracer {
	int val;
	void out(const string& s, int nv)
	{
		cerr << s << ": " << val << " (" << nv << ")\n";
	}
	Tracer() { out("Tracer()", 0); val = 0; }
	Tracer(int v) { val = v; out("Tracer(int)", v); }
	Tracer(const Tracer& t) { val = t.val; out("Tracer(Tracer&) ", t.val); }
	Tracer& operator=(const Tracer& a)
	{
		out("Tracer::operator=()", a.val);
		val = a.val; return *this;
	}
	~Tracer() { out("~Tracer()", 0); }
};

Tracer glob(2);
Tracer copy(Tracer a) { return a; }
Tracer copy2(Tracer a) { Tracer aa = a; return aa; }
Tracer& ref_to(Tracer& a) { return a; }
Tracer* make(int i) { Tracer a(i); return new Tracer(a); }
struct TracerTracer { Tracer a; Tracer b; };
int main()
{
	Tracer loc{ 4 };
	Tracer loc2{ loc };
	loc = Tracer{ 5 };
	loc2 = copy(loc);
	loc2 = copy2(loc);
	Tracer loc3{ 6 };
	Tracer& r = ref_to(loc);
	delete make(7);
	delete make(8);
	vector<Tracer> v(4);
	TracerTracer loc4;
	Tracer* p = new Tracer{ 9 };
	delete p;
	Tracer* pp = new Tracer[5];
	delete[] pp;

	keep_window_open();
}