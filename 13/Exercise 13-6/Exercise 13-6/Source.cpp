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

struct Box : Shape
{
	Box(Point p, int ww, int hh, string s)
		:w{ ww }, h{ hh }, label{ Point{ p.x + 10, p.y + h - 10 }, s } {
		add(p);
		label.set_font_size(20);
		label.set_font(Font::times);
	}
	void draw_lines() const;
	
private:
	int w;
	int h;
	Text label;
};

void Box::draw_lines() const
{
	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());
		fl_rectf(point(0).x, point(0).y, w, h);
		fl_color(color().as_int());
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_rect(point(0).x, point(0).y, w, h);
	}

	label.draw_lines();
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Box window{ Point{ 50, 50 }, 100, 40, "Window" };
	window.set_fill_color(Color::yellow);
	win.attach(window);
	Box line_style{ Point{ 180, 50 }, 100, 40, "Line_style" };
	line_style.set_fill_color(Color::yellow);
	win.attach(line_style);
	Box color{ Point{ 310, 50 }, 80, 40, "Color" };
	color.set_fill_color(Color::yellow);
	win.attach(color);

	Box simple_window{ Point{ 20, 180 }, 160, 40, "Simple_Window" };
	simple_window.set_fill_color(Color::yellow);
	win.attach(simple_window);
	Box point{ Point{ 400, 180 }, 80, 40, "Point" };
	point.set_fill_color(Color::yellow);
	win.attach(point);

	Box shape{ Point{ 220, 130 }, 80, 40, "Shape" };
	shape.set_fill_color(Color::yellow);
	win.attach(shape);

	Arrow simple_window2window{ Point { 100, 180 }, Point{ 100, 90 } };
	win.attach(simple_window2window);
	
	Box line{ Point{ 20, 320 }, 60, 40, "Line" };
	line.set_fill_color(Color::yellow);
	win.attach(line);
	Box lines{ Point{ 90, 320 }, 60, 40, "Lines" };
	lines.set_fill_color(Color::yellow);
	win.attach(lines);
	Box polygon{ Point{ 160, 320 }, 80, 40, "Polygon" };
	polygon.set_fill_color(Color::yellow);
	win.attach(polygon);
	Box axis{ Point{ 250, 320 }, 60, 40, "Axis" };
	axis.set_fill_color(Color::yellow);
	win.attach(axis);
	Box rectangle{ Point{ 320, 320 }, 100, 40, "Rectangle" };
	rectangle.set_fill_color(Color::yellow);
	win.attach(rectangle);
	Box text{ Point{ 430, 320 }, 60, 40, "Text" };
	text.set_fill_color(Color::yellow);
	win.attach(text);
	Box image{ Point{ 500, 320 }, 70, 40, "Image" };
	image.set_fill_color(Color::yellow);
	win.attach(image);

	Arrow line2shape{ Point{ 50, 320 }, Point{ 260 - 12, 170 } };
	win.attach(line2shape);
	Arrow lines2shape{ Point{ 120, 320 }, Point{ 260 - 8, 170 } };
	win.attach(lines2shape);
	Arrow polygon2shape{ Point{ 200, 320 }, Point{ 260 - 4, 170 } };
	win.attach(polygon2shape);
	Arrow axis2shape{ Point{ 280, 320 }, Point{ 260, 170 } };
	win.attach(axis2shape);
	Arrow rectangle2shape{ Point{ 370, 320 }, Point{ 260 + 4, 170 } };
	win.attach(rectangle2shape);
	Arrow text2shape{ Point{ 460, 320 }, Point{ 260 + 8, 170 } };
	win.attach(text2shape);
	Arrow image2shape{ Point{ 535, 320 }, Point{ 260 + 12, 170 } };
	win.attach(image2shape);

	win.wait_for_button();
}