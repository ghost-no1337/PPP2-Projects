#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point pl{ 100, 100 };
	Simple_window win{ pl, 600, 400, "Canvas" };

	Text j{ Point{0,150}, "J" };
	j.set_font_size(150);
	j.set_font(Font::times_bold);
	j.set_color(Color::cyan);

	Text q{ Point{ 100,150 }, "Q" };
	q.set_font_size(150);
	q.set_font(Font::times_bold);
	q.set_color(Color::blue);

	Text x{ Point{ 200,150 }, "X" };
	x.set_font_size(150);
	x.set_font(Font::times_bold);
	x.set_color(Color::dark_blue);

	win.attach(j);
	win.attach(q);
	win.attach(x);

	win.wait_for_button();
}