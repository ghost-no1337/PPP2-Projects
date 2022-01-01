#include "../../std_lib_facilities.h"
#include "../../Graph.h"
#include "../../GUI.h"
#include "../../Window.h"
#include <Windows.h>
#include <chrono>

using namespace Graph_lib;
using namespace chrono;

const int hour_ch = 1;
const int minute_ch = 2;
const int second_ch = 3;

int get_time(int time)
{
	time_t rawtime = system_clock::to_time_t(system_clock::now());
	string raw = ctime(&rawtime);

	regex time_pat{ R"(\w{3} \w{3} \d{2} (\d{2})\:(\d{2})\:(\d{2}) \d{4})" };
	smatch matches;

	regex_search(raw, matches, time_pat);
	return from_string<int>(matches[time]);
}

struct Clock : Shape
{
	Clock(Point xy);
	void draw_lines() const;
	void set_color(Color c);
	void update_hands();

	Line hour;
	Line minute;
	Line second;
private:
	Circle clock;
};

Clock::Clock(Point xy)
	:clock{ xy, 100 },
	hour{ xy, Point{ xy.x, xy.y - 50 } },
	minute{ xy, Point{ xy.x, xy.y - 70 } },
	second{ xy, Point{ xy.x, xy.y - 90 } }
{
	add(xy);
	hour.set_style(Line_style{ Line_style::solid, 3 });
	minute.set_style(Line_style{ Line_style::solid, 2 });
	second.rotate(get_time(second_ch) * 6, 90);
	minute.rotate(int(get_time(minute_ch) * 6 + get_time(second_ch) / 10), 70);
	hour.rotate(int(get_time(hour_ch) * 30 + get_time(minute_ch) / 2 + get_time(second_ch) / 120), 50);
}

void Clock::draw_lines() const
{
	clock.draw();
	hour.draw();
	minute.draw();
	second.draw();
}

void Clock::set_color(Color c)
{
	clock.set_color(c);
	hour.set_color(c);
	minute.set_color(c);
	second.set_color(c);
}

void Clock::update_hands()
{
	second.set_point(1, Point{ point(0).x, point(0).y - 90 });
	second.rotate(get_time(second_ch) * 6, 90);
	minute.set_point(1, Point{ point(0).x, point(0).y - 70 });
	minute.rotate(int(get_time(minute_ch) * 6 + get_time(second_ch) / 10), 70);
	hour.set_point(1, Point{ point(0).x, point(0).y - 50 });
	hour.rotate(int(get_time(hour_ch) * 30 + get_time(minute_ch) / 2 + get_time(second_ch) / 120), 50);
}

int main()
{
	Window win{ Point{ 100, 100 }, 600, 400, "Clock" };
	Clock clock{ Point{ 300, 200 } };
	win.attach(clock);
	Fl::redraw();

	while (true) {
		Fl::wait();
		Sleep(1000);
		Fl::awake();
		clock.update_hands();
		Fl::redraw();
	}

	return gui_main();
}