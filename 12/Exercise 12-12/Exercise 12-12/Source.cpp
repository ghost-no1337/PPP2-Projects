#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

double absolute(double x)
{
	if (x >= 0)
		return x;
	else
		return -x;
}

double y(double a, double b, double m, double n, double x)
{
	return pow(1 - pow(absolute(x / a), m), 1 / n) * b;
}

double minus_y(double a, double b, double m, double n, double x)
{
	return -pow(1 - pow(absolute(x / a), m), 1 / n) * b;
}

void sortvp(vector<Point> &vp)
{
	vector<Point> vpcopy = vp;
	vector<int> vx;
	for (Point p : vp)
		vx.push_back(p.x);
	
	for (int i = 0; i < vx.size(); ++i)
		for (Point p : vpcopy)
			if (vx[i] == p.x)
				vp[i] = p;
}

int main()
try {
	// Get data:
	cout << "Please enter a, b, m, n:\n";
	double a = 0, b = 0, n = 0, m = 0;
	cin >> a >> b >> m >> n;
	if (a <= 0 || b <= 0 || m <= 0 || n <= 0)
		error("a, b, m and n must be positive numbers");

	vector<Point> superellipse1;
	vector<Point> superellipse2;

	for (double x = -a + 0.001; x < a; x += 0.001) {
		superellipse1.push_back(Point{ int(100 * (a + x)), int(100 * (b + y(a, b, m, n, x))) });
	}

	for (double x = -a + 0.001; x < a; x += 0.01) {
		superellipse2.push_back(Point{ int(100 * (a + x)), int(100 * (b + minus_y(a, b, m, n, x))) });
	}

	sortvp(superellipse1);
	sortvp(superellipse2);

	// Draw:
	Point tl{ 100, 100 };
	Simple_window win{ tl, int(2 * 100 * a), int(2 * 100 * b), "Canvas" };

	Open_polyline polyline1;
	for (Point p : superellipse1)
		polyline1.add(p);
	polyline1.set_color(Color::red);
	win.attach(polyline1);

	Open_polyline polyline2;
	for (Point p : superellipse2)
		polyline2.add(p);
	polyline2.set_color(Color::blue);
	win.attach(polyline2);

	win.wait_for_button();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open("~~");
	return -1;
}