#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 1000, 800, "Canvas"};

	Lines grid;
	for (int i = 0; i <= 800; i += 100)
		grid.add(Point{ i, 0 }, Point{ i, 800 });
	for (int i = 0; i <= 800; i += 100)
		grid.add(Point{ 0, i }, Point{ 800, i });
	win.attach(grid);

	Vector_ref<Rectangle> vr;

	for (int i = 0; i <= 700; i += 100) {
		vr.push_back(new Rectangle{ Point{ i, i }, 100, 100 });
		vr[vr.size() - 1].set_fill_color(Color::red);
		win.attach(vr[vr.size() - 1]);
	}

	Vector_ref<Image> ir;

	for (int i = 200; i <= 600; i += 200) {
		ir.push_back(new Image{ Point{ 0, i }, "image.jpg" });
		ir[ir.size() - 1].set_mask(Point{ 0, 0 }, 200, 200);
		win.attach(ir[ir.size() - 1]);
	}

	Image img{ Point{ 0, 0 }, "rita.jpg" };
	img.set_mask(Point{ 0, 0 }, 100, 100);
	win.attach(img);

	while (true) {
		for (int i = 0; i < 28; ++i) {
			win.wait_for_button();
			if (i >= 0 && i < 7)
				img.move(100, 0);
			else if (i >= 7 && i < 14)
				img.move(0, 100);
			else if (i >= 14 && i < 21)
				img.move(-100, 0);
			else if (i >= 21 && i < 28)
				img.move(0, -100);
		}
	}
}