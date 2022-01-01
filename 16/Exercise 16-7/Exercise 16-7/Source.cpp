#include "../../Graph.h"
#include "../../GUI.h"
#include "../../Window.h"
#include "../../std_lib_facilities.h"
#include <Windows.h>

using namespace Graph_lib;

struct StartStop_Window : Window
{
	StartStop_Window(Point xy, int w, int h, const string& title);
private:
	Button start_button;
	Button stop_button;
	Image img;

	void start();
	void stop() { Fl::wait(); }

	static void cb_start(Address, Address);
	static void cb_stop(Address, Address);
};

StartStop_Window::StartStop_Window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	start_button{ Point{ x_max() - 150, 0 }, 70, 20, "Start", cb_start },
	stop_button{ Point{ x_max() - 70, 0 }, 70, 20, "Stop", cb_stop },
	img{ Point{ 0, 0 }, "image.jpg" }
{
	attach(start_button);
	attach(stop_button);
	attach(img);
	img.set_mask(Point{ 290, 0 }, 100, 100);
}

void StartStop_Window::cb_start(Address, Address pw)
{
	reference_to<StartStop_Window>(pw).start();
}

void StartStop_Window::cb_stop(Address, Address pw)
{
	reference_to<StartStop_Window>(pw).stop();
}

int counter = 0;
void StartStop_Window::start()
{
	Fl::awake();
	while (true) {
		Fl::wait();
		Sleep(500);
		Fl::awake();
		if (counter >= 0 && counter < 7)
			img.move(100, 0);
		else if (counter >= 7 && counter < 14)
			img.move(0, 100);
		else if (counter >= 14 && counter < 21)
			img.move(-100, 0);
		else if (counter >= 21 && counter < 28)
			img.move(0, -100);
		++counter;
		if (counter == 28)
			counter = 0;
		Fl::redraw();
	}
}

int main()
{
	StartStop_Window win{ Point{ 100, 100 }, 800, 800, "Plane" };
	return gui_main();
}