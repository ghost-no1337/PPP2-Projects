#include "../../std_lib_facilities.h"

struct Point
{
	double x;
	double y;
};

bool operator== (Point p1, Point p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return true;
	return false;
}

bool operator!= (vector<Point> v1, vector<Point> v2)
{
	if (v1.size() != v2.size())
		return true;
	
	for (int i = 0; i < v1.size(); ++i)
		if (v1[i] == v2[i])
			return false;
	return true;
}

istream &operator >> (istream &is, Point &p)
{
	char ch1, ch2, ch3;
	double x, y;
	is >> ch1 >> x >> ch2 >> y >> ch3; //format: (x,y)

	if (is.eof())
		return is;
	if (!is)
		error("Bad input");
	if (ch1 != '(' || ch2 != ',' || ch3 != ')')
		error("Bad input format");

	p = Point{ x,y };
	return is;
}

ostream &operator << (ostream &os, const Point &p)
{
	return os << '(' << p.x << ',' << p.y << ')';
}

void cout_points(const vector<Point> &points, string name)
{
	cout << name;
	for (Point p : points)
		cout << p << '\n';
}

void print_points(ofstream &ost, const vector<Point> &points, string name)
{
	ost << name;
	for (Point p : points)
		ost << p << '\n';
}

void get_points(ifstream &ist, vector<Point> &points)
{
	while (true) {
		Point p;
		ist >> p;
		if (ist.eof())
			return;
		if (!ist)
			error("Bad input from file");
		points.push_back(p);
	}
}

int main()
try {
	vector<Point> original_points;
	vector<Point> processed_points;

	cout << "Please enter 7 Points in the format of (x,y):\n";
	for (int i = 0; i < 7; ++i) {
		Point p;
		cin >> p;
		original_points.push_back(p);
	}

	ofstream ost{ "mydata.txt" };
	print_points(ost, original_points, "");
	ost.close();
	cout << "\nOutput Successful!\n";

	ifstream ist{ "mydata.txt" };
	get_points(ist, processed_points);
	ist.close();
	cout << "Input Successdul!\n";

	cout_points(original_points, "\noriginal_points:\n");
	cout_points(processed_points, "\nprocessed_points:\n");
	if (original_points != processed_points)
		cout << "\nSomething's wrong!\n";

	keep_window_open();
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