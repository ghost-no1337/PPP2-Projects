#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct Immobile_Circle : Circle
{
	using Circle::Circle;
	using Circle::draw_lines;
	void move(int x, int y) {
		error("can't move immobile circle");
	}
};

int main()
try {
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Immobile_Circle ic{ Point{ 300, 200 }, 100 };
	win.attach(ic);
	ic.move(100, 0);
	
	win.wait_for_button();
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}