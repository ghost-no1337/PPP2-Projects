#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int length(Point p1, Point p2)
{
	return int(pow(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2), 0.5));
}

struct Arrow : Shape
{
	Arrow(Point p1, Point p2) {
		add(p1); 
		add(p2); 
		arr.add(p2);
		arr.add(Point{ int(p2.x - 5.0 * (p2.x - p1.x) / length(p1, p2) +
			2.0 * (5.0 * (p2.y - p1.y) / length(p1, p2)) / 5.0), 
			int(p2.y - 5.0 * (p2.y - p1.y) / length(p1, p2) - 
			2.0 * (5.0 * (p2.x - p1.x) / length(p1, p2)) / 5.0) });
		arr.add(Point{ int(p2.x - 5.0 * (p2.x - p1.x) / length(p1, p2) -
			2.0 * (5.0 * (p2.y - p1.y) / length(p1, p2)) / 5.0),
			int(p2.y - 5.0 * (p2.y - p1.y) / length(p1, p2) +
			2.0 * (5.0 * (p2.x - p1.x) / length(p1, p2)) / 5.0) });
		arr.set_fill_color(Color::black);
	}
	void draw_lines() const;
private:
	Polygon arr;
};

void Arrow::draw_lines() const
{
	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());
		arr.draw_lines();
	}
	
	if (color().visibility()) {
		fl_color(color().as_int());
		fl_line(point(0).x, point(0).y, point(1).x, point(1).y);
		arr.draw_lines();
	}
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Arrow a{ Point{200, 300}, Point{200, 100} };
	win.attach(a);

	win.wait_for_button();
}