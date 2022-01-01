#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct Box : Shape {
	Box(Point p, int ww, int hh, int aa)
		:w{ ww }, h{ hh }, a{ aa } {
		add(p);
	}
	void draw_lines() const;
private:
	int w;
	int h;
	int a;
};

void Box::draw_lines() const
{
	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		fl_rectf(point(0).x + a, point(0).y + a, w - 2 * a, h - 2 * a);
		fl_rectf(point(0).x + a, point(0).y, w - 2 * a, a);
		fl_rectf(point(0).x, point(0).y + a, a, h - 2 * a);
		fl_rectf(point(0).x + a, point(0).y + h - a, w - 2 * a, a);
		fl_rectf(point(0).x + w - a, point(0).y + a, a, h - 2 * a);

		fl_pie(point(0).x, point(0).y, 2 * a, 2 * a, 90, 180);
		fl_pie(point(0).x, point(0).y + h - 2 * a, 2 * a, 2 * a, 180, 270);
		fl_pie(point(0).x + w - 2 * a, point(0).y + h - 2 * a, 2 * a, 2 * a, 270, 0);
		fl_pie(point(0).x + w - 2 * a, point(0).y, 2 * a, 2 * a, 0, 90);

		fl_color(color().as_int());
	}

	if (color().visibility()) {
		fl_color(color().as_int());

		fl_line(point(0).x + a, point(0).y, point(0).x + w - a, point(0).y);
		fl_line(point(0).x + a, point(0).y + h, point(0).x + w - a, point(0).y + h);
		fl_line(point(0).x, point(0).y + a, point(0).x, point(0).y + h - a);
		fl_line(point(0).x + w, point(0).y + a, point(0).x + w, point(0).y + h - a);

		fl_arc(point(0).x, point(0).y, 2 * a, 2 * a, 90, 180);
		fl_arc(point(0).x, point(0).y + h - 2 * a, 2 * a, 2 * a, 180, 270);
		fl_arc(point(0).x + w - 2 * a, point(0).y + h - 2 * a, 2 * a, 2 * a, 270, 0);
		fl_arc(point(0).x + w - 2 * a, point(0).y, 2 * a, 2 * a, 0, 90);
	}
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Box b{ tl, 300, 200, 50 };
	win.attach(b);

	win.wait_for_button();
}