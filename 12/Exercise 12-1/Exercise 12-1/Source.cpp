#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Rectangle rect{ Point{100, 50}, 200, 100 };
	win.attach(rect);

	Polygon poly;
	poly.add(Point{ 100, 250 });
	poly.add(Point{ 300, 250 });
	poly.add(Point{ 300, 350 });
	poly.add(Point{ 100, 350 });
	win.attach(poly);

	poly.set_color(Color::red);
	rect.set_color(Color::blue);

	win.wait_for_button();
}