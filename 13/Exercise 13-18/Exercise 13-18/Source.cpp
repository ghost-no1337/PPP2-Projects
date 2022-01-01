#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct Poly : Polygon 
{
	Poly(vector<Point> points);
	void add(Point p);
	using Polygon::draw_lines;
};

Poly::Poly(vector<Point> ps)
{
	for (int i = 0; i<ps.size(); ++i)
		add(ps[i]);
}

void Poly::add(Point p)
{
	Polygon::add(p);
}

int main()
try {
	Point tl{ 100, 100 };
	Simple_window win(tl, 600, 400, "Canvas");

	vector<Point> points;
	points.push_back(Point{ 200, 100 });
	points.push_back(Point{ 300, 100 });
	points.push_back(Point{ 300, 200 });
	points.push_back(Point{ 250, 200 });
	points.push_back(Point{ 200, 150 });

	Poly p(points);
	win.attach(p);

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