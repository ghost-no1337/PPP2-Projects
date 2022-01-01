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

	for (int i = 20 * cos(pi / 6); i < 600; i += 2 * 20 * cos(pi / 6))
		for (int j = 0.5 * 20; j < 400; j += 1.5 * 20) {
			vp.push_back(new Regular_polygon{ Point{ i, j }, 3, 20, 180 });
			win.attach(vp[vp.size() - 1]);
		}

	win.wait_for_button();
}