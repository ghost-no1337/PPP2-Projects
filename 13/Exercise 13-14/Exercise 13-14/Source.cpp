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

struct Right_triangle : Polygon
{
	Right_triangle(Point p, int r, int d) {
		for (int i = d; i < 360 + d; i += 120)
			add(Point{ p.x - sin(i * pi / 180) * r, p.y - cos(i * pi / 180) * r });
	}
	using Polygon::draw_lines;
};

int main()
try {
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Regular_polygon rp{ Point {300, 200}, 8, 80, 0 };
	rp.set_color(Color::invisible);
	win.attach(rp);

	Vector_ref<Right_triangle> rt;

	for (int i = 0; i < 8; ++i) {
		rt.push_back(new Right_triangle{ rp.point(i), 50, i * 45 + 60 });
		rt[rt.size() - 1].set_fill_color(i);
		win.attach(rt[rt.size() - 1]);
	}

	win.wait_for_button();
}
catch (exception &e) {
	cerr << e.what();
	keep_window_open();
}