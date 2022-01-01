#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;
constexpr double pi = 3.1415927;

struct Regular_polygon : Polygon
{
	Regular_polygon(Point p, int n, int r, int d) {
		if (n < 3)
			error("The number of sides is less than 3.");
		for (int i = d; i < 360 + d; i += 360 / n)
			add(Point{ p.x - sin(i * pi / 180) * r, p.y - cos(i * pi / 180) * r });
	}
	using Polygon::draw_lines;
};

struct Star : Polygon
{
	Star(Point p, int n, int r, int d) {
		if (n < 3)
			error("The number of sides is less than 3.");
		for (int i = d; i < 360 + d; i += 360 / n)
			outside.push_back(Point{ p.x - sin(i * pi / 180) * r, p.y - cos(i * pi / 180) * r });
		for (int i = d + 180 / n; i < 360 + d + 180 / n; i += 360 / n)
			inside.push_back(Point{ p.x - sin(i * pi / 180) * r / 3, p.y - cos(i * pi / 180) * r / 3 });
		for (int i = 0; i < outside.size(); ++i) {
			add(outside[i]);
			add(inside[i]);
		}
	}
	using Polygon::draw_lines;
private:
	vector<Point> outside;
	vector<Point> inside;
};

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Star s1{ Point{ 300, 200 }, 6, 100, 0 };
	win.attach(s1);

	Star s2{ Point{ 100, 100 }, 5, 50, 0 };
	s2.set_color(Color::blue);
	s2.set_style(Line_style(Line_style::solid, 4));
	s2.set_fill_color(Color::red);
	win.attach(s2);

	win.wait_for_button();
}