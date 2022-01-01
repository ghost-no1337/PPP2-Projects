#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Rectangle house{ Point{100, 200}, 300, 200 };
	house.set_color(Color::dark_green);
	house.set_fill_color(Color::dark_green);
	win.attach(house);

	Polygon roof;
	roof.add(Point{ 100, 200 });
	roof.add(Point{ 400, 200 });
	roof.add(Point{ 350, 150 });
	roof.add(Point{ 150, 150 });
	roof.set_color(Color::dark_blue);
	roof.set_fill_color(Color::dark_blue);
	win.attach(roof);

	Rectangle door{ Point{150, 275}, 50, 125 };
	door.set_color(Color::yellow);
	door.set_fill_color(Color::yellow);
	win.attach(door);

	Rectangle window1{ Point{ 250, 285 }, 50, 50 };
	window1.set_color(Color::cyan);
	window1.set_fill_color(Color::cyan);
	win.attach(window1);

	Rectangle window2{ Point{ 325, 285 }, 50, 50 };
	window2.set_color(Color::cyan);
	window2.set_fill_color(Color::cyan);
	win.attach(window2);

	Rectangle chimney{ Point{300, 75}, 50, 75 };
	chimney.set_color(Color::dark_yellow);
	chimney.set_fill_color(Color::dark_yellow);
	win.attach(chimney);

	Circle smoke{ Point{400, 25}, 15 };
	smoke.set_color(Color::white);
	smoke.set_fill_color(Color::white);
	win.attach(smoke);

	win.wait_for_button();
}