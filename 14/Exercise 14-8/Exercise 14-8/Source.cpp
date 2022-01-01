#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;
constexpr double pi = 3.1415927;

struct Octagon : Polygon
{
	Octagon(Point p, int d) {
		for (int i = 0; i < 360; i += 360 / 8)
			add(Point{ p.x - sin(i * pi / 180) * d, p.y - cos(i * pi / 180) * d });
	}
	using Polygon::draw_lines;
};

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Octagon oct{ Point{ 300, 200 }, 100 };
	win.attach(oct);

	oct.move(50, 50);
	oct.set_color(Color::blue);
	oct.set_fill_color(Color::cyan);
	oct.set_style(Line_style::dashdotdot);

	win.wait_for_button();
}