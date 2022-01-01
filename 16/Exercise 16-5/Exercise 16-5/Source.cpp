#include "../../GUI.h"
#include "../../Graph.h"
#include "../../Window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;
const double pi = 3.1415927;

const int circle = 0;
const int square = 1;
const int equal_tri = 2;
const int hexagon = 3;

struct Regular_polygon : Polygon
{
	Regular_polygon(Point p, int n, int d) {
		if (n < 3)
			error("The number of sides is less than 3.");
		for (int i = 0; i < 360; i += 360 / n)
			add(Point{ int(p.x - sin(i * pi / 180) * d), int(p.y - cos(i * pi / 180) * d) });
	}
	using Polygon::draw_lines;
};

struct Shape_window : Window {
	Shape_window(Point xy, int w, int h, const string& title);
private:
	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu menu;
	Vector_ref<Shape> shapes;

	int shape;

	void show(int i);

	void circle_pressed() { show(circle); menu.hide(); next(); }
	void square_pressed() { show(square); menu.hide(); next(); }
	void equal_tri_pressed() { show(equal_tri); menu.hide(); next(); }
	void hexagon_pressed() { show(hexagon); menu.hide(); next(); }
	void next();
	void quit();

	static void cb_circle(Address, Address);
	static void cb_square(Address, Address);
	static void cb_equal_tri(Address, Address);
	static void cb_hexagon(Address, Address);
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);
};

Shape_window::Shape_window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	menu{ Point{ x_max() - 70, 30 }, 70, 20, Menu::vertical, "color" },
	next_button{ Point{ x_max() - 150, 0 }, 70, 20, "Next point", cb_next },
	quit_button{ Point{ x_max() - 70, 0 }, 70, 20, "Quit", cb_quit },
	next_x{ Point{ x_max() - 310, 0 }, 50, 20, "next x:" },
	next_y{ Point{ x_max() - 210, 0 }, 50, 20, "next y:" },
	xy_out{ Point{ 100, 0 }, 100, 20, "current (x,y):" }
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");
	menu.attach(new Button{ Point{ 0, 0 }, 0, 0, "circle", cb_circle });
	menu.attach(new Button{ Point{ 0, 0 }, 0, 0, "square", cb_square });
	menu.attach(new Button{ Point{ 0, 0 }, 0, 0, "equal tri", cb_equal_tri });
	menu.attach(new Button{ Point{ 0, 0 }, 0, 0, "hexagon", cb_hexagon });
	attach(menu);
	shapes.push_back(new Circle{ Point{ x_max() / 2, y_max() / 2 }, 100 });
	shapes.push_back(new Rectangle{ Point{ x_max() / 2 - 100, y_max() / 2 - 100 }, Point{ x_max() / 2 + 100, y_max() / 2 + 100 } });
	shapes.push_back(new Regular_polygon{ Point{ x_max() / 2, y_max() / 2 }, 3, 100 });
	shapes.push_back(new Regular_polygon{ Point{ x_max() / 2, y_max() / 2 }, 6, 100 });
	attach(shapes[circle]);
	attach(shapes[square]);
	attach(shapes[equal_tri]);
	attach(shapes[hexagon]);
	shapes[circle].set_color(Color::invisible);
	shapes[square].set_color(Color::invisible);
	shapes[equal_tri].set_color(Color::invisible);
	shapes[hexagon].set_color(Color::invisible);
}

void Shape_window::show(int i)
{
	for (int j = 0; j < 4; ++j)
		shapes[j].set_color(Color::invisible);

	shape = i;
	shapes[i].set_color(Color::black);
}

void Shape_window::cb_quit(Address, Address pw)
{
	reference_to<Shape_window>(pw).quit();
}

void Shape_window::quit()
{
	hide();
}

void Shape_window::cb_next(Address, Address pw)
{
	reference_to<Shape_window>(pw).next();
}

void Shape_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();

	int x_orig;
	int y_orig;
	switch (shape) {
	case circle: case square:
		x_orig = shapes[shape].point(0).x + 100;
		y_orig = shapes[shape].point(0).y + 100;
		break;
	case equal_tri: case hexagon:
		x_orig = shapes[shape].point(0).x;
		y_orig = shapes[shape].point(0).y + 100;
		break;
	}

	shapes[shape].move(x - x_orig, y - y_orig);

	stringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

void Shape_window::cb_circle(Address, Address pw)
{
	reference_to<Shape_window>(pw).circle_pressed();
}

void Shape_window::cb_square(Address, Address pw)
{
	reference_to<Shape_window>(pw).square_pressed();
}

void Shape_window::cb_equal_tri(Address, Address pw)
{
	reference_to<Shape_window>(pw).equal_tri_pressed();
}

void Shape_window::cb_hexagon(Address, Address pw)
{
	reference_to<Shape_window>(pw).hexagon_pressed();
}

int main()
try {
	Shape_window win{ Point{ 100, 100 }, 600, 400, "Shapes" };
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