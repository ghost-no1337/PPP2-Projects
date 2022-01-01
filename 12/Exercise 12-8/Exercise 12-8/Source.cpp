#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Circle ring1{ Point{ 150, 150 }, 75 };
	ring1.set_color(Color::blue);
	ring1.set_style(Line_style(Line_style::solid, 6));
	win.attach(ring1);

	Circle ring2{ Point{ 230, 230 }, 75 };
	ring2.set_color(Color::yellow);
	ring2.set_style(Line_style(Line_style::solid, 6));
	win.attach(ring2);

	Circle ring3{ Point{ 310, 150 }, 75 };
	// Color is black
	ring3.set_style(Line_style(Line_style::solid, 6));
	win.attach(ring3);

	Circle ring4{ Point{ 390, 230 }, 75 };
	ring4.set_color(Color::dark_green);
	ring4.set_style(Line_style(Line_style::solid, 6));
	win.attach(ring4);

	Circle ring5{ Point{ 470, 150 }, 75 };
	ring5.set_color(Color::red);
	ring5.set_style(Line_style(Line_style::solid, 6));
	win.attach(ring5);

	win.wait_for_button();
}