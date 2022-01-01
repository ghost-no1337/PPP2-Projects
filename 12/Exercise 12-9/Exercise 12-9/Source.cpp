#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Snow Cpp" };

	Image snow_cpp{ tl, "snow_cpp.gif" };
	win.attach(snow_cpp);

	Text label{ Point{ 100, 80 }, "Snow Cpp" };
	label.set_font_size(20);
	win.attach(label);

	win.wait_for_button();
}