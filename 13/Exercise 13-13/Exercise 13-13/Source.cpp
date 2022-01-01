#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };
	
	Vector_ref<Rectangle> vr;

	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 16; ++j) {
			vr.push_back(new Rectangle{ Point{ i * 20, j * 20 }, 20, 20 });
			vr[vr.size() - 1].set_color(Color::invisible);
			vr[vr.size() - 1].set_fill_color(Color{ i * 16 + j });
			win.attach(vr[vr.size() - 1 ]);
		}

	win.wait_for_button();
}