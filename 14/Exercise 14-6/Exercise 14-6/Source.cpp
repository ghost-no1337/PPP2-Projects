#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct Striped_circle : Circle
{
	Striped_circle(Point p, int r)
		:Circle(p, r) {
		for (int i = 0; i < r; i += 2) {
			stripes1.add(Point{ p.x - sqrt(r * r - i * i), static_cast<double>(p.y - i) },
				Point{ p.x + sqrt(r * r - i * i), static_cast<double>(p.y - i) });
			stripes1.add(Point{ p.x - sqrt(r * r - i * i), static_cast<double>(p.y + i) },
				Point{ p.x + sqrt(r * r - i * i), static_cast<double>(p.y + i) });
		}
		for (int i = 1; i < r; i += 2) {
			stripes2.add(Point{ p.x - sqrt(r * r - i * i), static_cast<double>(p.y - i) },
				Point{ p.x + sqrt(r * r - i * i), static_cast<double>(p.y - i) });
			stripes2.add(Point{ p.x - sqrt(r * r - i * i), static_cast<double>(p.y + i) },
				Point{ p.x + sqrt(r * r - i * i), static_cast<double>(p.y + i) });
		}
	}
	void draw_lines() const;

	void set_stripes_color(Color c, int i);
	void set_stripes_style(Line_style l, int i);

	void set_fill_color(Color c) {
		set_stripes_color(c, 1);
		set_stripes_color(c, 2);
	}
private:
	Lines stripes1;
	Lines stripes2;
};

void Striped_circle::draw_lines() const
{
	Circle::draw_lines();
	stripes1.draw_lines();
	stripes2.draw_lines();
}

void Striped_circle::set_stripes_color(Color c, int i)
{
	switch (i) {
	case 1:
		stripes1.set_color(c);
		return;
	case 2:
		stripes2.set_color(c);
		return;
	}
}

void Striped_circle::set_stripes_style(Line_style l, int i)
{
	switch (i) {
	case 1:
		stripes1.set_style(l);
		return;
	case 2:
		stripes2.set_style(l);
		return;
	}
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Striped_circle sc{ Point{ 300, 200 }, 100 };
	sc.set_stripes_color(Color::blue, 2);
	win.attach(sc);

	win.wait_for_button();
}