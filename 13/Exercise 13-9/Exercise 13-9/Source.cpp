#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;
constexpr double pi = 3.1415927;

struct Regular_hexagon : Polygon
{
	Regular_hexagon(Point p, int d) {
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

	Vector_ref<Regular_hexagon> rh;
	for (int i = 100; i < 600; i += 300) {
		for (int j = 0; j < 400; j += int(2 * cos(30 * pi / 180) * 100)) {
			rh.push_back(new Regular_hexagon{ Point{ i, j }, 100 });
			win.attach(rh[rh.size() - 1]);
		}
	}
	for (int i = 250; i < 600; i += 300) {
		for (int j = int(cos(30 * pi / 180) * 100); j < 400; 
			j += int(2 * cos(30 * pi / 180) * 100)) {
			rh.push_back(new Regular_hexagon{ Point{ i, j }, 100 });
			win.attach(rh[rh.size() - 1]);
		}
	}

	win.wait_for_button();
}