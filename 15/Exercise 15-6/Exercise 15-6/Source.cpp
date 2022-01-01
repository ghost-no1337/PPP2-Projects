#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

double smallest(vector<double> v)
{
	sort(v);
	return v[0];
}

double biggest(vector<double> v)
{
	sort(v);
	return v[v.size() - 1];
}

struct Bar_chart : Shape
{
	Bar_chart(Point xy, vector<double> &v, vector<string> &labels, int width = 50);

	void add_value(double d);
	int value(int i) { return values[i]; }
	int size() { return values.size(); };
	void add_label(int i, string s) { label[i].set_label(s); }

	void move(int dx, int dy);
	void draw_lines() const;

	Vector_ref<Rectangle> bar;
	Vector_ref<Text> label;
private:
	int wdth;
	int sc;
	vector<double> values;
};

Bar_chart::Bar_chart(Point xy, vector<double> &v, vector<string> &labels, int width)
	: wdth{ width } {
	add(xy);
	if (smallest(v) < 0)
		error("Bad input: negative numbers");

	if (biggest(v) * 25 >= xy.y)
		sc = int(xy.y / biggest(v));
	else
		sc = 25;

	for (int i = 0; i < v.size(); ++i) {
		add_value(v[i]);
		add_label(i, labels[i]);
	}
	label.push_back(new Text{ Point{ point(0).x, int(point(0).y - biggest(values) * sc) }, "" });
}

void Bar_chart::add_value(double d)
{
	if (d < 0)
		error("bad input: negative number");
	values.push_back(d);

	bar.push_back(new Rectangle{ Point{ static_cast<int>(point(0).x + (values.size() - 1) * wdth), int(point(0).y - d * sc) }, wdth, int(d * sc) });
	label.push_back(new Text{ Point{ static_cast<int>(point(0).x + (values.size() - 1) * wdth), point(0).y + 20 }, "" });
}

void Bar_chart::move(int dx, int dy)
{
	Shape::move(dx, dy);
	for (int i = 0; i < bar.size(); ++i)
		bar[i].move(dx, dy);
	for (int i = 0; i < label.size(); ++i)
		label[i].move(dx, dy);
}

void Bar_chart::draw_lines() const
{
	for (int i = 0; i < bar.size(); ++i)
		bar[i].draw();
	for (int i = 0; i < label.size(); ++i)
		label[i].draw();
}

int main()
try {
	cout << "Please enter input file name: ";
	string ifname;
	cin >> ifname;
	ifstream ifs{ ifname };
	if (!ifs)
		error("can't find the input file");

	vector<double> values;
	vector<string> labels;

	char ch1, ch2, ch3;
	int i;
	double d;
	while (ifs >> ch1 >> i >> ch2 >> d >> ch3) {
		if (ch1 != '(' || ch2 != ',' || ch3 != ')')
			ifs.clear(ios_base::failbit);
		values.push_back(d);
		labels.push_back(to_string(i));
	}

	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Axis x{ Axis::x, Point{ 100, 350 }, int(values.size() * 50), int(values.size()) };
	win.attach(x);
	Axis y{ Axis::y, Point{ 100, 350 }, 300, 10 };
	win.attach(y);

	Bar_chart bc{ Point{ 100, 350 }, values, labels };
	bc.label[bc.label.size() - 1].set_label("Heights");
	bc.label[bc.label.size() - 1].move(20, 50);
	bc.label[bc.label.size() - 1].set_font(Font::times);
	bc.label[bc.label.size() - 1].set_font_size(20);
	win.attach(bc);

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