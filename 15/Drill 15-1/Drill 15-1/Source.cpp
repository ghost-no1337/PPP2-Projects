#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }

double sloping_cos(double x)
{
	return x / 2 + cos(x);
}

int main()
{
	Point pl{ 100, 100 };
	Simple_window win{ pl, 600, 600, "Function graphs" };

	const Point orig{ 300, 300 };
	const int length = 400;
	const int notch = 20;

	Axis x(Axis::x, Point{ orig.x - length / 2, orig.y }, length, length / 20, "l == 20 pixels");
	Axis y(Axis::y, Point{ orig.x, orig.y + length / 2 }, length, length / 20, "l == 20 pixels");
	win.attach(x);
	win.attach(y);
	x.set_color(Color::red);
	y.set_color(Color::red);

	Function f1{ one, -10, 11, orig, 400, 20, 20 };
	win.attach(f1);

	Function f2{ slope, -10, 11, orig, 400, 20, 20 };
	win.attach(f2);
	Text t2{ Point{ 100, 380 }, "x/2" };
	win.attach(t2);

	Function f3{ square, -10, 11, orig, 400, 20, 20 };
	win.attach(f3);

	Function f4{ cos, -10, 11, orig, 400, 20, 20 };
	win.attach(f4);
	f4.set_color(Color::blue);

	Function f5{ sloping_cos, -10, 11, orig, 400, 20, 20 };
	win.attach(f5);

	win.wait_for_button();
}