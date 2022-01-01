#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

Point n(Rectangle &rect)
{
	return Point{ rect.point(0).x + int(0.5 * rect.width()), rect.point(0).y };
}

Point s(Rectangle &rect)
{
	return Point{ int(rect.point(0).x + 0.5 * rect.width()), rect.point(0).y + rect.height() };
}

Point e(Rectangle &rect)
{
	return Point{ rect.point(0).x + rect.width(), int(rect.point(0).y + 0.5 * rect.height()) };
}

Point w(Rectangle &rect)
{
	return Point{ rect.point(0).x, int(rect.point(0).y + 0.5 * rect.height()) };
}

Point center(Rectangle &rect)
{
	return Point{ int(rect.point(0).x + 0.5 * rect.width()), int(rect.point(0).y + 0.5 * rect.height()) };
}

Point ne(Rectangle &rect)
{
	return Point{ rect.point(0).x + rect.width(), rect.point(0).y };
}

Point se(Rectangle &rect)
{
	return Point{ rect.point(0).x + rect.width(), rect.point(0).y + rect.height() };
}

Point sw(Rectangle &rect)
{
	return Point{ rect.point(0).x, rect.point(0).y + rect.height() };
}

Point nw(Rectangle &rect)
{
	return rect.point(0);
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Rectangle rect{ tl, 400, 200 };
	win.attach(rect);

	Marks m { "x" };
	m.add(n(rect));
	m.add(s(rect));
	m.add(e(rect));
	m.add(w(rect));
	m.add(center(rect));
	m.add(ne(rect));
	m.add(se(rect));
	m.add(sw(rect));
	m.add(nw(rect));
	win.attach(m);

	win.wait_for_button();
}