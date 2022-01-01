#include "../../GUI.h"
#include "../../Graph.h"
#include "../../Window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

constexpr char sin_ch = 'S';
constexpr char log_ch = 'L';

struct Function_window : Window
{
	Function_window(Point xy, int w, int h, const string& title);
private:
	Button draw;
	Menu function;
	Out_box function_out;
	In_box orig_x;
	In_box orig_y;
	In_box xscale;
	In_box yscale;

	Axis x;
	Axis y;
	Vector_ref<Function> vf;

	char function_ch = sin_ch;

	void draw_function();
	void sin_pressed() { function_ch = sin_ch; function_out.put("sin()"); }
	void log_pressed() { function_ch = log_ch; function_out.put("log()"); }

	static void cb_draw(Address, Address);
	static void cb_sin(Address, Address);
	static void cb_log(Address, Address);
};

Function_window::Function_window(Point xy, int w, int h, const string& title)
	:Window{ xy, w, h, title },
	draw{ Point{ x_max() - 70, 0 }, 70, 60, "Draw", cb_draw },
	function{ Point{ x_max() - 400, 20 }, 70, 20, Menu::vertical, "functions" },
	function_out{ Point{ x_max() - 400, 0 }, 70, 20, "function:" },
	orig_x{ Point{ x_max() - 250, 0 }, 50, 20, "Orig x:" },
	orig_y{ Point{ x_max() - 130, 0 }, 50, 20, "Orig y:" },
	xscale{ Point{ x_max() - 250, 30 }, 50, 20, "x scale:" },
	yscale{ Point{ x_max() - 130, 30 }, 50, 20, "y scale:" },
	x{ Axis::x, Point{ 100, y_max() / 2 }, x_max() - 200 },
	y{ Axis::y, Point{ x_max() / 2, y_max() - 100 }, y_max() - 200 }
{
	attach(draw);
	function.attach(new Button{ Point{ 0, 0 }, 0, 0, "sin()", cb_sin });
	function.attach(new Button{ Point{ 0, 0 }, 0, 0, "log()", cb_log });
	attach(function);
	attach(function_out);
	attach(orig_x);
	attach(orig_y);
	attach(xscale);
	attach(yscale);
	attach(x);
	attach(y);
}

void Function_window::draw_function()
{
	if (vf.size() != 0)
		for (int i = 0; i < vf.size(); ++i)
			vf[i].set_color(Color::invisible);
	if (xscale.get_int() <= 0 || yscale.get_int() <= 0)
		error("bad input: negative scale");

	switch (function_ch) {
	case sin_ch:
		vf.push_back(new Function{ sin, -10, 11, 
			Point{ orig_x.get_int() + x_max() / 2, orig_y.get_int() + y_max() / 2 },
			100, double(xscale.get_int()), double(yscale.get_int()) });
		attach(vf[vf.size() - 1]);
		break;
	case log_ch:
		vf.push_back(new Function{ log, -10, 11, 
			Point{ orig_x.get_int() + x_max() / 2, orig_y.get_int() + y_max() / 2 },
			100, double(xscale.get_int()), double(yscale.get_int()) });
		attach(vf[vf.size() - 1]);
		break;
	}
	Fl::redraw();
}

void Function_window::cb_draw(Address, Address pw)
{
	reference_to<Function_window>(pw).draw_function();
}

void Function_window::cb_sin(Address, Address pw)
{
	reference_to<Function_window>(pw).sin_pressed();
}

void Function_window::cb_log(Address, Address pw)
{
	reference_to<Function_window>(pw).log_pressed();
}

int main()
try {
	Function_window win{ Point{100, 100},600, 400, "Function window" };
	return gui_main();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}