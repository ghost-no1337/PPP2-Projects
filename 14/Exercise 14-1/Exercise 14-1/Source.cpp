#include "../../Graph.h"
#include "../../Simple_window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct Arc : Shape {
	Arc(Point p, int ww, int hh, int ab, int ae)
		:h{ hh }, w{ ww }, a1{ ab }, a2{ ae } {
		add(Point{ p.x - w, p.y - h });
	}
	void draw_lines() const;
private:
	Point p;
	int w;
	int h;
	int a1;
	int a2;
};

void Arc::draw_lines() const
{
	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());
		fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, a1, a2);
		fl_color(color().as_int());
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, w + w, h + h, a1, a2);
	}
}

struct Smiley : Circle
{
	Smiley(Point p, int rr)
		:Circle(p, rr),
		eye1(Point{ p.x - rr / 5, p.y - rr / 2 }, rr / 8, rr / 3),
		eye2(Point{ p.x + rr / 5, p.y - rr / 2 }, rr / 8, rr / 3),
		mouth(p, int(rr * 0.5), (rr * 0.5), 180, 360) { }
	void draw_lines() const;

	void set_eyes_color(Color c);
	void set_mouth_color(Color c);
private:
	Ellipse eye1;
	Ellipse eye2;
	Arc mouth;
};

void Smiley::draw_lines() const
{
	Circle::draw_lines();
	eye1.draw_lines();
	eye2.draw_lines();
	mouth.draw_lines();
}

void Smiley::set_eyes_color(Color c)
{
	eye1.set_color(c);
	eye2.set_color(c);
}

void Smiley::set_mouth_color(Color c)
{
	mouth.set_color(c);
}

struct Smiley_with_hat : Smiley
{
	Smiley_with_hat(Point p, int rr)
		:Smiley(p, rr){
		hat.add(Point{ static_cast<double>(p.x - rr), p.y - rr * 0.75 });
		hat.add(Point{ static_cast<double>(p.x + rr), p.y - rr * 0.75 });
		hat.add(Point{ static_cast<double>(p.x), p.y - rr * 1.5 });
		hat.set_fill_color(Color::black);
	}
	void draw_lines() const;

	void set_hat_color(Color c);
private:
	Polygon hat;
};

void Smiley_with_hat::draw_lines() const
{
	Smiley::draw_lines();
	hat.draw_lines();
}

void Smiley_with_hat::set_hat_color(Color c)
{
	hat.set_fill_color(c);
}

struct Frowny : Circle
{
	Frowny(Point p, int rr)
		:Circle(p, rr),
		eye1(Point{ p.x - rr / 5, p.y - rr / 2 }, rr / 8, rr / 3),
		eye2(Point{ p.x + rr / 5, p.y - rr / 2 }, rr / 8, rr / 3),
		mouth(Point{ static_cast<double>(p.x), p.y + rr * 0.5 }, int(rr * 0.5), (rr * 0.5), 0, 180) { }
	void draw_lines() const;

	void set_eyes_color(Color c);
	void set_mouth_color(Color c);
private:
	Ellipse eye1;
	Ellipse eye2;
	Arc mouth;
};

void Frowny::draw_lines() const
{
	Circle::draw_lines();
	eye1.draw_lines();
	eye2.draw_lines();
	mouth.draw_lines();
}

void Frowny::set_eyes_color(Color c)
{
	eye1.set_color(c);
	eye2.set_color(c);
}

void Frowny::set_mouth_color(Color c)
{
	mouth.set_color(c);
}

struct Frowny_with_hat : Frowny
{
	Frowny_with_hat(Point p, int rr)
		:Frowny(p, rr) {
		hat.add(Point{ static_cast<double>(p.x - rr), p.y - rr * 0.75 });
		hat.add(Point{ static_cast<double>(p.x + rr), p.y - rr * 0.75 });
		hat.add(Point{ static_cast<double>(p.x), p.y - rr * 1.5 });
		hat.set_fill_color(Color::black);
	}
	void draw_lines() const;

	void set_hat_color(Color c);
private:
	Polygon hat;
};

void Frowny_with_hat::draw_lines() const
{
	Frowny::draw_lines();
	hat.draw_lines();
}

void Frowny_with_hat::set_hat_color(Color c)
{
	hat.set_fill_color(c);
}

int main()
{
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Smiley_with_hat s{ Point{ 300, 200 }, 100 };
	win.attach(s);
	win.wait_for_button();

	Frowny_with_hat f{ Point{ 300, 200 }, 100 };
	win.attach(f);
	win.wait_for_button();
}