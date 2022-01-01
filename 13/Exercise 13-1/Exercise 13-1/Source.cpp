#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct Arc : Shape {
	Arc(Point p, int ww, int hh, int ab, int ae)
		:h{ hh }, w{ ww }, a1{ ab }, a2{ ae } {
		add(Point{ p.x - w, p.y - h });
	}
	void draw_lines() const;
private:
	Point p;
	int w;
	int h;
	int a1;
	int a2;
};

void Arc::draw_lines() const
{
	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());
		fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, a1, a2);
		fl_color(color().as_int());
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, w + w, h + h, a1, a2);
	}
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Arc a{ Point{200, 200}, 100, 100, 0, 90 };
	win.attach(a);

	win.wait_for_button();
}