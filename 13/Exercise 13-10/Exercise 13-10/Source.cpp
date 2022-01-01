#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;
constexpr double pi = 3.1415927;

struct Regular_polygon : Polygon
{
	Regular_polygon(Point p, int n, int d) {
		if (n < 3)
			error("The number of sides is less than 3.");
			for(int i = 0; i < 360; i += 360 / n)
				add(Point{ p.x - sin(i * pi / 180) * d, p.y - cos(i * pi / 180) * d });
	}
	using Polygon::draw_lines;
};

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Regular_polygon rp{ Point{ 300, 200 }, 6, 100 };
	win.attach(rp);

	win.wait_for_button();
}