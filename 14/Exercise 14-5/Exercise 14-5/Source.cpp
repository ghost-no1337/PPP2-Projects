#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct Striped_rectangle : Rectangle
{
	Striped_rectangle(Point p, int x, int y)
		:Rectangle(p, x, y) {
		for (int i = p.y + 1; i < p.y + y; i += 2)
			stripes1.add(Point{ p.x, i }, Point{ p.x + x, i });
		for (int i = p.y + 2; i < p.y + y; i += 2)
			stripes2.add(Point{ p.x, i }, Point{ p.x + x, i });
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

void Striped_rectangle::draw_lines() const
{
	Rectangle::draw_lines();
	stripes1.draw_lines();
	stripes2.draw_lines();
}

void Striped_rectangle::set_stripes_color(Color c, int i)
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

void Striped_rectangle::set_stripes_style(Line_style l, int i)
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

	Striped_rectangle sr{ Point{150, 100}, 300, 200 };
	sr.set_stripes_color(Color::blue, 2);
	win.attach(sr);

	win.wait_for_button();
}