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

struct Pseudo_window : Box
{
	Pseudo_window(Point p, int ww, int hh, string s)
		:Box{ p, ww, hh, 10 },
		label{ Point{ p.x + 10, p.y + 20 }, s },
		min{ Point{ p.x + ww - 75, p.y + 5 }, 20, 20, 5 },
		max{ Point{ p.x + ww - 50, p.y + 5 }, 20, 20, 5 },
		close{ Point{ p.x + ww - 25, p.y + 5 }, 20, 20, 5 }
	{
		label.set_font(Font::helvetica);
		label.set_font_size(12);
		min.set_fill_color(Color::green);
		max.set_fill_color(Color::yellow);
		close.set_fill_color(Color::red);
	}
	void draw_lines() const;
private:
	Text label;
	Box min;
	Box max;
	Box close;
};

void Pseudo_window::draw_lines() const
{
	Box::draw_lines();
	label.draw_lines();
	min.draw_lines();
	max.draw_lines();
	close.draw_lines();
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Pseudo_window pwin{ tl, 300, 200, "Canvas" };
	win.attach(pwin);

	win.wait_for_button();
}