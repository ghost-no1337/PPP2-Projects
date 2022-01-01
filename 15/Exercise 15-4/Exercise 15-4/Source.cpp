#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

double get_sum(double x)
{
	return sin(x) + cos(x);
}

double get_square_sum(double x)
{
	return sin(x)*sin(x) + cos(x)*cos(x);
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 600, "Canvas" };

	const Point orig{ 300, 300 };
	const int length = 400;
	const int notch = 20;

	Axis x(Axis::x, Point{ orig.x - length / 2, orig.y }, length, length / 20, "X Axis");
	Axis y(Axis::y, Point{ orig.x, orig.y + length / 2 }, length, length / 20, "Y Axis");
	win.attach(x);
	win.attach(y);

	Function sine{ sin, -10, 11, orig };
	win.attach(sine);

	Function cosine{ cos, -10, 11, orig };
	win.attach(cosine);

	Function sum{ get_sum, -10, 11, orig };
	win.attach(sum);

	Function square_sum{ get_square_sum, -10, 11, orig };
	win.attach(square_sum);

	win.wait_for_button();
}