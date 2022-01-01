#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"
#include <cmath>

using namespace Graph_lib;

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 1000, 800, "Canvas" };
	constexpr double pi = 3.1415926;

	Polygon tri;
	tri.add(Point{ 500, 100 });
	tri.add(Point{ 500 + 150, 100 + int(sqrt(3) * 300 / 2) });
	tri.add(Point{ 500 - 150, 100 + int(sqrt(3) * 300 / 2) });
	win.attach(tri);

	Polygon squ;
	squ.add(Point{ 500, 100 });
	squ.add(Point{ 500 + int(sqrt(2) * 300 / 2), 100 + int(sqrt(2) * 300 / 2) });
	squ.add(Point{ 500, 100 + 2 * int(sqrt(2) * 300 / 2) });
	squ.add(Point{ 500 - int(sqrt(2) * 300 / 2), 100 + int(sqrt(2) * 300 / 2) });
	win.attach(squ);

	Polygon pent;
	pent.add(Point{ 500, 100 });
	pent.add(Point{ 500 + int(sin(54 * pi / 180) * 300), 100 + int(cos(54 * pi / 180) * 300) });
	pent.add(Point{ 500 + 150,
		100 + int(cos(54 * pi / 180) * 300) + int(sin(72 * pi / 180) * 300) });
	pent.add(Point{ 500 - 150,
		100 + int(cos(54 * pi / 180) * 300) + int(sin(72 * pi / 180) * 300) });
	pent.add(Point{ 500 - int(sin(54 * pi / 180) * 300), 100 + int(cos(54 * pi / 180) * 300) });
	win.attach(pent);

	win.wait_for_button();
}