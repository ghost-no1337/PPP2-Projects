#include "../../std_lib_facilities.h"
#include "../../Simple_window.h"
#include "../../Graph.h"

using namespace Graph_lib;

struct bad_from_string : std::bad_cast {
	const char* what() const override
	{
		return "bad cast from string";
	}
};

template<typename T> T from_string(const string& s)
{
	istringstream is{ s };
	T t;
	if (!(is >> t))
		throw bad_from_string{};
	return t;
}

Shape* analyze(string& command)
{
	regex circle_pattern{ R"(Circle\{\s?Point\{\s?(\d+),\s?(\d+)\s?\},\s?(\d+)\s?\})" };
	regex rectangle_pattern1{ R"(Rectangle\{\s?Point\{\s?(\d+),\s?(\d+)\s?\},\s?(\d+),\s?(\d+)\s?\})" };
	regex rectangle_pattern2{ R"(Rectangle\{\s?Point\{\s?(\d+),\s?(\d+)\s?\},\s?Point\{\s?(\d+),\s?(\d+)\s?\}\s?\})" };

	smatch matches;
	if (regex_match(command, matches, circle_pattern)) {
		Circle* temp = new Circle{ Point{from_string<int>(matches[1]), from_string<int>(matches[2]) },
			from_string<int>(matches[3]) };
		return temp;
	}
	if (regex_match(command, matches, rectangle_pattern1)) {
		Rectangle* temp = new Rectangle{ Point{ from_string<int>(matches[1]), from_string<int>(matches[2]) },
			from_string<int>(matches[3]), from_string<int>(matches[4]) };
		return temp;
	}
	if (regex_match(command, matches, rectangle_pattern2)) {
		Rectangle* temp = new Rectangle{ Point{ from_string<int>(matches[1]), from_string<int>(matches[2]) },
			Point{ from_string<int>(matches[3]), from_string<int>(matches[4]) } };
		return temp;
	}

	error("wrong input format");
}

int main()
try {
	Simple_window win{ Point{ 100, 100 }, 600, 400, "GUI Test" };

	for (string command; getline(cin, command); ) {
		win.attach(*analyze(command));
		win.wait_for_button();
	}

	return gui_main();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}