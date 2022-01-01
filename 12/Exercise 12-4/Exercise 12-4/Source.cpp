#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Rectangle rect1{ Point{100, 100}, 50, 50 };
	rect1.set_style(Line_style(Line_style::solid, 4));
	rect1.set_color(Color::white);
	rect1.set_fill_color(Color::white);
	win.attach(rect1);

	Rectangle rect2{ Point{ 100, 200 }, 50, 50 };
	rect2.set_style(Line_style(Line_style::solid, 4));
	rect2.set_color(Color::white);
	rect2.set_fill_color(Color::white);
	win.attach(rect2);

	Rectangle rect3{ Point{ 150, 150 }, 50, 50 };
	rect3.set_style(Line_style(Line_style::solid, 4));
	rect3.set_color(Color::white);
	rect3.set_fill_color(Color::white);
	win.attach(rect3);

	Rectangle rect4{ Point{ 200, 100 }, 50, 50 };
	rect4.set_style(Line_style(Line_style::solid, 4));
	rect4.set_color(Color::white);
	rect4.set_fill_color(Color::white);
	win.attach(rect4);

	Rectangle rect5{ Point{ 200, 200 }, 50, 50 };
	rect5.set_style(Line_style(Line_style::solid, 4));
	rect5.set_color(Color::white);
	rect5.set_fill_color(Color::white);
	win.attach(rect5);

	Rectangle rect6{ Point{ 150, 100 }, 50, 50 };
	rect6.set_style(Line_style(Line_style::solid, 4));
	rect6.set_color(Color::red);
	rect6.set_fill_color(Color::red);
	win.attach(rect6);

	Rectangle rect7{ Point{ 100, 150 }, 50, 50 };
	rect7.set_style(Line_style(Line_style::solid, 4));
	rect7.set_color(Color::red);
	rect7.set_fill_color(Color::red);
	win.attach(rect7);

	Rectangle rect8{ Point{ 150, 200 }, 50, 50 };
	rect8.set_style(Line_style(Line_style::solid, 4));
	rect8.set_color(Color::red);
	rect8.set_fill_color(Color::red);
	win.attach(rect8);

	Rectangle rect9{ Point{ 200, 150 }, 50, 50 };
	rect9.set_style(Line_style(Line_style::solid, 4));
	rect9.set_color(Color::red);
	rect9.set_fill_color(Color::red);
	win.attach(rect9);

	win.wait_for_button();
}