#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Rectangle rect{ Point{100, 50}, 100, 30 };
	Text t{ Point{120, 70}, "Howdy!" };

	win.attach(rect);
	win.attach(t);

	win.wait_for_button();
}