#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;
constexpr double pi = 3.1415927;

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Circle c{ Point{ 300, 200 }, 100 };
	win.attach(c);

	Mark m{ Point{400, 200}, 'x' };
	win.attach(m);

	while (true)
		for (int i = 0; i < 360; i += 5) {
			win.wait_for_button();
			m.move(int(100 * (cos(i * pi / 180) - cos((i - 5) * pi / 180))),
				int(100 * (sin((i - 5)* pi / 180) - sin(i * pi / 180))));
	}
}