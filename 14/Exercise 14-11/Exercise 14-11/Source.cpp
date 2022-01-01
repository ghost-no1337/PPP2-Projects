#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

int length(Point p1, Point p2)
{
	return int(pow(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2), 0.5));
}

struct Arrow : Shape
{
	Arrow(Point p1, Point p2) {
		add(p1);
		add(p2);
		arr.add(p2);
		arr.add(Point{ int(p2.x - 5.0 * (p2.x - p1.x) / length(p1, p2) +
			2.0 * (5.0 * (p2.y - p1.y) / length(p1, p2)) / 5.0),
			int(p2.y - 5.0 * (p2.y - p1.y) / length(p1, p2) -
				2.0 * (5.0 * (p2.x - p1.x) / length(p1, p2)) / 5.0) });
		arr.add(Point{ int(p2.x - 5.0 * (p2.x - p1.x) / length(p1, p2) -
			2.0 * (5.0 * (p2.y - p1.y) / length(p1, p2)) / 5.0),
			int(p2.y - 5.0 * (p2.y - p1.y) / length(p1, p2) +
				2.0 * (5.0 * (p2.x - p1.x) / length(p1, p2)) / 5.0) });
		arr.set_fill_color(Color::black);
	}
	void draw_lines() const;
private:
	Polygon arr;
};

void Arrow::draw_lines() const
{
	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());
		arr.draw_lines();
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_line(point(0).x, point(0).y, point(1).x, point(1).y);
		arr.draw_lines();
	}
}

constexpr double pi = 3.1415927;

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

struct Binary_tree : Shape {
	Binary_tree(Point p, int l, string line_style);
	virtual void draw_lines() const;
	void move(int dx, int dy);
	int show_levels() const { return levels; }
	void set_label(string n, string lebel);
protected:
	Vector_ref<Shape> lines;
	Vector_ref<Text> labels;
private:
	int levels;
};

struct Binary_tree_triangle : Binary_tree {
	using Binary_tree::Binary_tree;
	void draw_lines() const;
};

Binary_tree::Binary_tree(Point p, int l, string line_style) 
	:levels{ l }
{
	if (levels < 0) 
		error("Binary_tree: levels must be at least zero");
	if (levels == 0) return;
	add(p);

	int dx = 35;
	int dy = 50;

	for (int i = 2; i <= levels; ++i) {
		for (int j = 0; j < pow(2, i - 1); ++j) {
			int x = p.x - ((pow(2, i - 1) - 1) / 2 - j) * pow(2, levels - i) * dx;
			int y = p.y + (i - 1)*dy;
			add(Point{ x, y });
		}
	}

	for (int i = 0; i<number_of_points() / 2; ++i)
		if (line_style == "Arrow_down") {
			lines.push_back(new Arrow(point(i),
				Point{ point(2 * i + 1).x, point(2 * i + 1).y - 12 }));
			lines.push_back(new Arrow(point(i),
				Point{ point(2 * i + 2).x, point(2 * i + 2).y - 12 }));
		}
		else if (line_style == "Arrow_up") {
			lines.push_back(new Arrow(point(2 * i + 1),
				Point{ point(i).x, point(i).y + 12 }));
			lines.push_back(new Arrow(point(2 * i + 2),
				Point{ point(i).x, point(i).y + 12 }));
		}
		else if (line_style == "Normal") {
			lines.push_back(new Line(point(i), point(2 * i + 1)));
			lines.push_back(new Line(point(i), point(2 * i + 2)));
		}

	for (int i = 0; i < number_of_points(); ++i)
		labels.push_back(new Text(Point{ point(i).x + 13, point(i).y - 13 }, ""));
}

void Binary_tree::draw_lines() const
{
	Vector_ref<Circle> circles;
	for (int i = 0; i < number_of_points(); ++i) {
		circles.push_back(new Circle{ point(i), 12 });
		circles[circles.size() - 1].set_fill_color(Color::yellow);
	}

	for (int i = 0; i < circles.size(); ++i)
		circles[i].draw();

	for (int i = 0; i < lines.size(); ++i)
		lines[i].draw();

	for (int i = 0; i < number_of_points(); ++i)
		labels[i].draw();
}

void Binary_tree::move(int dx, int dy)
{
	Shape::move(dx, dy);

	for (int i = 0; i < lines.size(); ++i)
		lines[i].move(dx, dy);

	for (int i = 0; i < number_of_points(); ++i)
		labels[i].move(dx, dy);
}

void Binary_tree::set_label(string n, string lebel)
{
	if (n.size() < 1 || n.size() > levels) 
		error("Bad node string ", n);

	istringstream iss{ n };
	char ch;
	iss.get(ch);    // look at first character
	if (n.size() == 1)
		switch (ch) {
		case 'l':
		case 'r':
			labels[0].set_label(lebel);
			return;
		default:
			error("Bad character in node string: ", string{ 1, ch });
		}

	int number = 0;
	while (iss.get(ch))
		switch (ch) {
		case 'l':
			number = 2 * number + 1;
			break;
		case 'r':
			number = 2 * number + 2;
			break;
		default:
			error("set_node_label: illegal character in node string: ", string(1, ch));
		}
	labels[number].set_label(lebel);
}

void Binary_tree_triangle::draw_lines() const
{
	Vector_ref<Regular_polygon> polygons;
	for (int i = 0; i < number_of_points(); ++i) {
		polygons.push_back(new Regular_polygon{ point(i), 3, 12 });
		polygons[polygons.size() - 1].set_fill_color(Color::yellow);
	}

	for (int i = 0; i < polygons.size(); ++i)
		polygons[i].draw();

	for (int i = 0; i < lines.size(); ++i)
		lines[i].draw();

	for (int i = 0; i < number_of_points(); ++i)
		labels[i].draw();
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Binary_tree bt{ Point{ 300, 100 }, 3, "Arrow_down" };
	win.attach(bt);

	win.wait_for_button();

	Binary_tree_triangle btt{ Point{ 300, 100 }, 3, "Arrow_down" };
	win.attach(btt);

	win.wait_for_button();
}