#include "../../Simple_window.h"
#include "../../Graph.h"
#include "../../std_lib_facilities.h"

struct Distribution {
	int month, locat1, locat2;
};

istream& operator >> (istream& is, Distribution& d)
// assume format: ( month : locat1 locat2 )
{
	char ch1 = 0;
	char ch2 = 0;
	char ch3 = 0;
	Distribution dd;

	if (is >> ch1 >> dd.month
		>> ch2 >> dd.locat1 >> dd.locat2 >> ch3) {
		if (ch1 != '(' || ch2 != ':' || ch3 != ')') {
			is.clear(ios_base::failbit);
			return is;
		}
	}
	else
		return is;
	d = dd;
	return is;
}

class Scale {
	int cbase;
	int vbase;
	double scale;
public:
	Scale(int b, int vb, double s) :cbase(b), vbase(vb), scale(s) { }
	int operator()(int v) const { return cbase + (v - vbase)*scale; }
};

int main()
try
{
	const int xmax = 700;
	const int ymax = 400;

	const int xoffset = 200;
	const int yoffset = 60;

	const int xspace = 40;
	const int yspace = 40;

	const int xlength = xmax - xoffset - xspace;
	const int ylength = ymax - yoffset - yspace;

	const int base_month = 1;
	const int end_month = 12;

	const double xscale = double(xlength) / (end_month - base_month);
	const double yscale = double(ylength) / 50;

	Scale xs(xoffset, base_month, xscale);
	Scale ys(ymax - yoffset, 0, -yscale);

	string file_name = "weather_data.txt";
	ifstream ifs{ file_name };
	if (!ifs) 
		error("can't open ", file_name);

	Open_polyline loc1;
	Open_polyline loc2;

	Distribution d;
	while (ifs >> d) {
		if (d.month < base_month || end_month < d.month) error("month out of range");
		int x = xs(d.month);
		loc1.add(Point{ x, ys(d.locat1) });
		loc2.add(Point{ x, ys(d.locat2) });
	}

	Simple_window win(Point{ 100, 100 }, xmax, ymax, "Temperatures");

	Axis x{ Axis::x, Point{ xoffset, ymax - yoffset }, xlength,
		end_month - base_month,
		"                        Month  1        2        3        4        5        "
		"6        7        8        9        10       11       12" };
	x.label.move(-100, 0);

	Axis y{ Axis::y, Point{ xoffset, ymax - yoffset }, ylength, 10, "Temperature in Celcius" };

	Text loc1_label{ Point{ 50, loc1.point(0).y }, "Cambridge, England" };
	loc1.set_color(Color::dark_green);
	loc1_label.set_color(Color::dark_green);

	Text loc2_label{ Point{ 20, loc2.point(0).y }, "Cambridge, Massachusetts" };
	loc2.set_color(Color::blue);
	loc2_label.set_color(Color::blue);

	win.attach(loc1);
	win.attach(loc2);

	win.attach(loc1_label);
	win.attach(loc2_label);

	win.attach(x);
	win.attach(y);

	win.wait_for_button();
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