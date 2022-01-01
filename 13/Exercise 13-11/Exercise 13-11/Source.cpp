#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Ellipse e{ Point{ 300, 200 }, 150, 100 };
	win.attach(e);

	Axis x{ Axis::x, Point{ 100, 200 }, 400, 10, "" };
	Axis y{ Axis::y, Point{ 300, 350 }, 300, 10, "" };
	win.attach(x);
	win.attach(y);
	
	Mark f1{ e.focus1(), 'x' };
	Mark f2{ e.focus2(), 'x' };
	win.attach(f1);
	win.attach(f2);

	Point p{ e.focus1().x, 
		e.focus1().y - int(double(100 * 100) / 150) };
	Mark mp{ p, 'x' };
	win.attach(mp);

	Line l1{ e.focus1(), p };
	Line l2{ e.focus2(), p };
	win.attach(l1);
	win.attach(l2);

	win.wait_for_button();
}