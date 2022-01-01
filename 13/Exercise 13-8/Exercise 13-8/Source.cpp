#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;
constexpr double pi = 3.1415927;

struct Regular_hexagon : Polygon
{
	Regular_hexagon(Point p, int d)	{
		add(Point{ p.x - d, p.y });
		add(Point{ p.x - sin(pi / 6) * d, p.y - cos(pi / 6) * d });
		add(Point{ p.x + sin(pi / 6) * d, p.y - cos(pi / 6) * d });
		add(Point{ p.x + d, p.y });
		add(Point{ p.x + sin(pi / 6) * d, p.y + cos(pi / 6) * d });
		add(Point{ p.x - sin(pi / 6) * d, p.y + cos(pi / 6) * d });
	}
	using Polygon::draw_lines;
};

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Regular_hexagon rh{ Point{300, 200}, 100 };
	win.attach(rh);

	win.wait_for_button();
}