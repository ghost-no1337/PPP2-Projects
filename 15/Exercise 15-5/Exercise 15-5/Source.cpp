#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;
const double pi = 3.1415927;

double leibniz(double n)
{
	if (int(n) % 2 != 1)
		error("bad n");
	double r = 1;
	while (n > 1) {
		if (int(n) % 4 == 1)
			r += 1.0 / n;
		else if (int(n) % 4 == 3)
			r -= 1.0 / n;
		n -= 2;
	}
	return r;
}

double constn = 0;
double constleibniz(double)
{
	return leibniz(constn);
}

double constpi(double) { return pi / 4; }

int main()
try {
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 600, "leibniz approximation" };

	Axis x{ Axis::x, Point{ 100, 300}, 400, 20, "X Axis" };
	Axis y{ Axis::y, Point{ 300, 500 }, 400, 20, "Y Axis" };
	win.attach(x);
	win.attach(y);

	Function pi{ constpi, -10, 11, Point{ 300, 300 } };
	win.attach(pi);
	pi.set_color(Color::blue);

	for (int n = 1; n < 50; n += 2) {
		ostringstream ss;
		ss << "exp approximation; n==" << n;
		win.set_label(ss.str());
		constn = n;

		Function l{constleibniz, -10, 11, Point{ 300, 300 }};
		win.attach(l);
		win.wait_for_button();
		win.detach(l);
	}
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return -1;
}