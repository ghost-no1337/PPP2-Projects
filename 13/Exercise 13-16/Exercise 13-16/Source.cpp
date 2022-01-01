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

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Vector_ref<Regular_polygon> vp;

	int counter = 0;

	for (int i = 20; i < 600; i += 3 * 20)
		for (int j = 20 * sin(60 * pi / 180); j < 400; j += 2 * 20 * sin(60 * pi / 180)) {
			vp.push_back(new Regular_polygon{ Point{ i, j }, 6, 20, 90 });
			vp[vp.size() - 1].set_fill_color(counter);
			win.attach(vp[vp.size() - 1]);
			++counter;
		}

	for (int i = 50; i < 600; i += 3 * 20)
		for (int j = 2 * 20 * sin(60 * pi / 180); j < 400; j += 2 * 20 * sin(60 * pi / 180)) {
			vp.push_back(new Regular_polygon{ Point{ i, j }, 6, 20, 90 });
			vp[vp.size() - 1].set_fill_color(counter);
			win.attach(vp[vp.size() - 1]);
			++counter;
		}

	win.wait_for_button();
}