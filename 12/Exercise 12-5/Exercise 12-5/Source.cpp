#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 50, 50 };
	Simple_window win{ tl, 1800, 900, "Canvas" };

	Rectangle rect_frame{ Point{ 50, 50 }, 1300, 775 };
	rect_frame.set_color(Color::red);
	rect_frame.set_fill_color(Color::red);
	win.attach(rect_frame);

	Rectangle rect_base{ Point{100, 100}, 1200, 675 };
	rect_base.set_color(Color::white);
	rect_base.set_fill_color(Color::white);
	win.attach(rect_base);

	win.wait_for_button();
}