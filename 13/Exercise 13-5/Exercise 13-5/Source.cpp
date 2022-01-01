#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"
#include <cmath>

using namespace Graph_lib;
constexpr double pi = 3.1415926;

Point n_c(Circle &c)
{
	return Point{ c.center().x, c.center().y - c.radius() };
}

Point s_c(Circle &c)
{
	return Point{ c.center().x, c.center().y + c.radius() };
}

Point e_c(Circle &c)
{
	return Point{ c.center().x + c.radius(), c.center().y };
}

Point w_c(Circle &c)
{
	return Point{ c.center().x - c.radius(), c.center().y };
}

Point center_c(Circle &c)
{
	return c.center();
}

Point ne_c(Circle &c)
{
	return Point{ c.center().x + c.radius() * cos(pi / 4), c.center().y - c.radius() * cos(pi / 4) };
}

Point se_c(Circle &c)
{
	return Point{ c.center().x + c.radius() * cos(3 * pi / 4), c.center().y - c.radius() * cos(3 * pi / 4) };
}

Point sw_c(Circle &c)
{
	return Point{ c.center().x + c.radius() * cos(5 * pi / 4), c.center().y - c.radius() * cos(5 * pi / 4) };
}

Point nw_c(Circle &c)
{
	return Point{ c.center().x + c.radius() * cos(7 * pi / 4), c.center().y - c.radius() * cos(7 * pi / 4) };
}

Point n_e(Ellipse &e)
{
	return Point{ e.center().x, e.center().y - e.minor() };
}

Point s_e(Ellipse &e)
{
	return Point{ e.center().x, e.center().y + e.minor() };
}

Point e_e(Ellipse &e)
{
	return Point{ e.center().x + e.major(), e.center().y };
}

Point w_e(Ellipse &e)
{
	return Point{ e.center().x - e.major(), e.center().y };
}

Point center_e(Ellipse &e)
{
	return e.center();
}

Point ne_e(Ellipse &e)
{
	return Point{ e.center().x + e.major() * cos(pi / 4), e.center().y - e.minor() * sin(pi / 4) };
}

Point se_e(Ellipse &e)
{
	return Point{ e.center().x + e.major() * cos(3 * pi / 4), e.center().y - e.minor() * sin(3 * pi / 4) };
}

Point sw_e(Ellipse &e)
{
	return Point{ e.center().x + e.major() * cos(5 * pi / 4), e.center().y - e.minor() * sin(5 * pi / 4) };
}

Point nw_e(Ellipse &e)
{
	return Point{ e.center().x + e.major() * cos(7 * pi / 4), e.center().y - e.minor() * sin(7 * pi / 4) };
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win1{ tl, 600, 400, "Canvas" };

	Circle c{ Point{300, 200}, 100 };
	win1.attach(c);

	Marks mc{ "x" };
	mc.add(n_c(c));
	mc.add(s_c(c));
	mc.add(e_c(c));
	mc.add(w_c(c));
	mc.add(center_c(c));
	mc.add(ne_c(c));
	mc.add(se_c(c));
	mc.add(sw_c(c));
	mc.add(nw_c(c));
	win1.attach(mc);

	win1.wait_for_button();

	Simple_window win2{ tl, 600, 400, "Canvas" };

	Ellipse e{ Point{ 300, 200 }, 200, 100 };
	win2.attach(e);

	Marks me{ "x" };
	me.add(n_e(e));
	me.add(s_e(e));
	me.add(e_e(e));
	me.add(w_e(e));
	me.add(center_e(e));
	me.add(ne_e(e));
	me.add(se_e(e));
	me.add(sw_e(e));
	me.add(nw_e(e));
	win2.attach(me);

	win2.wait_for_button();
}