#include "../../GUI.h"
#include "../../Window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct My_window : Window {
	My_window(Point xy, int w, int h, const string& title)
		: Window(xy, w, h, title),
		button_pushed(false),
		next_button(Point{ x_max() - 140, 0 }, 70, 20, "Next", cb_next),
		quit_button(Point{ x_max() - 70, 0 }, 70, 20, "Quit", cb_quit) {
	attach(next_button);
	attach(quit_button);
	}

	void wait_for_button()
	{
		while (!button_pushed) Fl::wait();
		button_pushed = false;
		Fl::redraw();
	}

	Button next_button;
	Button quit_button;
private:
	bool button_pushed;

	static void cb_next(Address, Address pw)
	{
		reference_to<My_window>(pw).next();
	}

	static void cb_quit(Address, Address pw)
	{
		reference_to<My_window>(pw).quit();
	}

	void next() 
	{
		button_pushed = true;
	}

	void quit()
	{
		hide();
	}
};

int main()
{
	My_window win{ Point{100, 100}, 600, 400, "My window" };
	win.wait_for_button();
}