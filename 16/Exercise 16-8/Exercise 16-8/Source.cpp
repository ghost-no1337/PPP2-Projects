#include "../../GUI.h"
#include "../../Window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

constexpr int USD = 0;
constexpr int EUR = 1;
constexpr int CNY = 2;

struct Converter_window : Window
{
	Converter_window(Point xy, int w, int h, const string& title);
private:
	Button convert_button;
	Out_box from_box;
	Menu from_menu;
	Out_box to_box;
	Menu to_menu;
	In_box input;
	Out_box output;

	void get_rate();
	vector<double> rates{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int in;
	int out;

	void convert();

	void input_USD() { in = USD; from_box.put("USD"); }
	void input_EUR() { in = EUR; from_box.put("EUR"); }
	void input_CNY() { in = CNY; from_box.put("CNY"); }
	void output_USD() { out = USD; to_box.put("USD"); }
	void output_EUR() { out = EUR; to_box.put("EUR");}
	void output_CNY() { out = CNY; to_box.put("CNY"); }

	static void cb_convert(Address, Address);
	static void cb_input_USD(Address, Address);
	static void cb_input_EUR(Address, Address);
	static void cb_input_CNY(Address, Address);
	static void cb_output_USD(Address, Address);
	static void cb_output_EUR(Address, Address);
	static void cb_output_CNY(Address, Address);
};

Converter_window::Converter_window(Point xy, int w, int h, const string& title)
	:Window{ xy, w, h, title },
	convert_button{ Point{ x_max() - 80, 0 }, 70, 60, "Convert", cb_convert },
	from_box{ Point{x_max() - 300, 0}, 70, 20, "from:" },
	from_menu{ Point{ x_max() - 300, 40 }, 70, 20, Menu::vertical, "from" },
	to_box{ Point{ x_max() - 200, 0 }, 70, 20, "to:" },
	to_menu{ Point{x_max() - 200, 40}, 70, 20, Menu::vertical, "to" },
	input{ Point{ x_max() - 300, 120 }, 100, 20, "input:" },
	output{ Point{ x_max() - 300, 170 }, 100, 20, "output:" }
{
	get_rate();
	attach(convert_button);
	attach(from_box);
	from_menu.attach(new Button{ Point{ 0, 0 }, 0, 0, "USD", cb_input_USD });
	from_menu.attach(new Button{ Point{ 0, 0 }, 0, 0, "EUR", cb_input_EUR });
	from_menu.attach(new Button{ Point{ 0, 0 }, 0, 0, "CNY", cb_input_CNY });
	attach(from_menu);
	attach(to_box);
	to_menu.attach(new Button{ Point{ 0, 0 }, 0, 0, "USD", cb_output_USD });
	to_menu.attach(new Button{ Point{ 0, 0 }, 0, 0, "EUR", cb_output_EUR });
	to_menu.attach(new Button{ Point{ 0, 0 }, 0, 0, "CNY", cb_output_CNY });
	attach(to_menu);
	attach(input);
	attach(output);
}

void Converter_window::get_rate()
{	// format: ( input_char -> output_char : rate )
	ifstream ifs{ "rate.txt" };
	if (!ifs)
		error("rate input file not found");
	char ch1, ch2, ch3, ch4, ch5;
	char inp, oup;
	double rate;
	while (ifs >> ch1 >> inp >> ch2 >> ch3 >> oup >> ch4 >> rate >> ch5) {
		if (ch1 != '(' || ch2 != '-' || ch3 != '>' ||
			ch4 != ':' || ch5 != ')')
			error("bad rate input format");
		if (rate <= 0)
			error("bad rate input: negative rate");

		int result = 0;
		switch (inp) {
		case 'U':
			result += USD * 3;
			break;
		case 'E':
			result += EUR * 3;
			break;
		case 'C':
			result += CNY * 3;
			break;
		default:
			error("bad rate input: money not found");
		}
		switch (oup) {
		case 'U':
			result += USD;
			break;
		case 'E':
			result += EUR;
			break;
		case 'C':
			result += CNY;
			break;
		default:
			error("bad rate input: money not found");
		}

		rates[result] = rate;
	}
	rates[USD * 4] = 1;
	rates[EUR * 4] = 1;
	rates[CNY * 4] = 1;

	for (double d : rates)
		if (d == 0)
			error("some inputs missing");
}

void Converter_window::convert()
{
	stringstream ss{ input.get_string() };
	double inumber;
	ss >> inumber;
	if (!ss)
		error("bad input");
	if (inumber < 0)
		error("bad input: negative number");
	double onumber = inumber * rates[in * 3 + out];
	ostringstream oss;
	oss << onumber;
	output.put(oss.str());
}

void Converter_window::cb_convert(Address, Address pw)
{
	reference_to<Converter_window>(pw).convert();
}

void Converter_window::cb_input_USD(Address, Address pw)
{
	reference_to<Converter_window>(pw).input_USD();
}

void Converter_window::cb_input_EUR(Address, Address pw)
{
	reference_to<Converter_window>(pw).input_EUR();
}

void Converter_window::cb_input_CNY(Address, Address pw)
{
	reference_to<Converter_window>(pw).input_CNY();
}

void Converter_window::cb_output_USD(Address, Address pw)
{
	reference_to<Converter_window>(pw).output_USD();
}

void Converter_window::cb_output_EUR(Address, Address pw)
{
	reference_to<Converter_window>(pw).output_EUR();
}

void Converter_window::cb_output_CNY(Address, Address pw)
{
	reference_to<Converter_window>(pw).output_CNY();
}

int main()
try {
	Converter_window win{ Point{100, 100}, 600, 400, "Converter" };
	return gui_main();
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