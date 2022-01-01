#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct Fct2 : Shape
{
	Fct2::Fct2(Fct f, double r1, double r2, Point xy, int count, double xscale, double yscale);

	void reset(Fct f, double r1, double r2, Point xy, int count, double xscale, double yscale);
	void reset_fct(Fct f) {
		reset(f, rg1, rg2, orig, cnt, xs, ys);
	}
	void reset_range(double r1, double r2) {
		reset(fct, r1, r2, orig, cnt, xs, ys);
	}
	void reset_point(Point p) {
		reset(fct, rg1, rg2, p, cnt, xs, ys);
	}
	void reset_scale(int count, double xscale, double yscale) {
		reset(fct, rg1, rg2, orig, count, xscale, yscale);
	}
private:
	Fct* fct;
	double rg1;
	double rg2;
	Point orig;
	int cnt;
	double xs;
	double ys;
};

Fct2::Fct2(Fct f, double r1, double r2, Point xy, int count, double xscale, double yscale)
	:fct{ f }, rg1{ r1 }, rg2{ r2 }, orig{ xy.x, xy.y }, cnt{ count }, xs{ xscale }, ys{ yscale } {
	if (r2 - r1 <= 0)
		error("bad graphing range");

	if (count <= 0)
		error("non-positive graphing count");
	double dist = (r2 - r1) / count;

	double r = r1;

	for (int i = 0; i<count; ++i) {
		add(Point{ xy.x + int(r*xscale), xy.y - int(f(r)*yscale) });
		r += dist;
	}
}

void Fct2::reset(Fct f, double r1, double r2, Point xy, int count, double xscale, double yscale)
{
	if (r2 - r1 <= 0)
		error("bad graphing range");

	if (count <= 0)
		error("non-positive graphing count");
	double dist = (r2 - r1) / count;

	double r = r1;

	clear_points();

	for (int i = 0; i<count; ++i) {
		add(Point{ xy.x + int(r*xscale), xy.y - int(f(r)*yscale) });
		r += dist;
	}
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Fct2 sine{ sin, -10, 11, Point{ 300, 200 }, 400, 30, 30 };
	win.attach(sine);

	win.wait_for_button();

	sine.reset_fct(cos);
	sine.reset_point(Point{ 300, 300 });

	win.wait_for_button();
}