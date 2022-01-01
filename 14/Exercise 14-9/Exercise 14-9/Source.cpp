#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct Group : Shape
{
	void add(Shape& s) {
		vs.push_back(s);
	}
	Shape& shape(int i);

	void draw() const;
	void move(int x, int y);
private:
	Vector_ref<Shape> vs;
};

Shape& Group::shape(int i)
{
	return vs[i];
}

void Group::draw() const
{
	for (int i = 0; i < vs.size(); ++i)
		vs[i].draw();
}

void Group::move(int x, int y)
{
	for (int i = 0; i < vs.size(); ++i)
		vs[i].move(x, y);
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Group g;

	Circle c{ Point{ 200, 200 }, 100 };
	win.attach(c);
	g.add(c);
	Rectangle rect{ Point{ 200, 100 }, 200, 200 };
	win.attach(rect);
	g.add(rect);

	g.move(100, 0);

	win.wait_for_button();
}