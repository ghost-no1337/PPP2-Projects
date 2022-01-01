#include "../../GUI.h"
#include "../../Graph.h"
#include "../../Window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

struct Purchase {
	string name;
	int unit_price;
	int count;
};

struct Order {
	string name;
	string address;
	vector<Purchase> purchases;
};

ostream& operator<<(ostream& os, const Purchase& p)
{
	return os << "{ " << p.name << ", " << p.unit_price << ", " << p.count << " }";
}

ostream& operator<<(ostream& os, const Order& o)
{
	os << "{ " << o.name << ", " << o.address << ", ";
	for (int i = 0; i < o.purchases.size(); ++i) {
		os << o.purchases[i];
		if (i + 1 != o.purchases.size())
			os << ", ";
		else os << " }";
	}
	return os;
}

bool file_loaded = false;
ofstream ofs;

struct Order_window : Window {
	Order_window(Point xy, int w, int h, const string& title);
private:
	Button next_button;
	Button quit_button;
	In_box order_name;
	In_box order_address;
	Button add_order;
	In_box purchase_name;
	In_box purchase_unit_price;
	In_box purchase_count;
	Button add_purchase;
	In_box output_file;
	Out_box output_display;

	Order* temp = nullptr;

	void next();
	void quit();

	void change_display(bool show);

	void order();
	void purchase();

	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);
	static void cb_add_order(Address, Address);
	static void cb_add_purchase(Address, Address);
};

Order_window::Order_window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	next_button{ Point{ x_max() - 150, 0 }, 70, 20, "Next", cb_next },
	quit_button{ Point{ x_max() - 70, 0 }, 70, 20, "Quit", cb_quit },
	order_name{ Point{ x_max() - 530, 50 }, 150, 20, "Order Name:" },
	order_address{ Point{ x_max() - 310, 50 }, 150, 20, "Order Address:" },
	add_order{ Point{ x_max() - 150, 50 }, 70, 20, "Add Order", cb_add_order },
	purchase_name{ Point{ x_max() - 530, 100 }, 150, 20, "Purchase Name:" },
	purchase_unit_price{ Point{ x_max() - 310, 100 }, 150, 20, "Purchase Unit Price:" },
	purchase_count{ Point{ x_max() - 530, 120 }, 150, 20, "Purchase Count:" },
	add_purchase{ Point{ x_max() - 150, 100 }, 70, 20, "Add Purchase", cb_add_purchase },
	output_file{ Point{ 100, 0 }, 150, 20, "Output File:" },
	output_display{ Point{ 100, 0 }, 150, 20, "Output File:" }
{
	attach(next_button);
	attach(quit_button);
	attach(order_name);
	attach(order_address);
	attach(add_order);
	attach(purchase_name);
	attach(purchase_unit_price);
	attach(purchase_count);
	attach(add_purchase);
	attach(output_file);
	attach(output_display);

	change_display(false);
}

void Order_window::change_display(bool show)
{
	if (show) {
		output_file.hide();
		output_display.show();

		order_name.show();
		order_address.show();
		add_order.show();
		purchase_name.show();
		purchase_unit_price.show();
		purchase_count.show();
		add_purchase.show();
	}
	else {
		output_file.show();
		output_display.hide();

		order_name.hide();
		order_address.hide();
		add_order.hide();
		purchase_name.hide();
		purchase_unit_price.hide();
		purchase_count.hide();
		add_purchase.hide();
	}
}

void Order_window::order()
{
	if (order_name.get_string() == "" || order_address.get_string() == "") {
		if (temp) {
			if (temp->name == "" || temp->address == "")
				error("Please enter the name/address of the Order");
			if (temp->purchases.size() == 0)
				error("Please add at least 1 Purchase first");
			ofs << (*temp);
			delete temp;
			temp = nullptr;
		}
	}
	else {
		temp = new Order();
		temp->name = order_name.get_string();
		temp->address = order_address.get_string();
	}
}

void Order_window::purchase()
{
	if (temp) {
		if (purchase_name.get_string() == "" || purchase_unit_price.get_string() == "" || purchase_count.get_string() == "")
			error("Please enter name/unit price/count of the Purchase");

		Purchase p;
		p.name = purchase_name.get_string();
		if (purchase_unit_price.get_int() > 0 && purchase_count.get_int() > 0) {
			p.unit_price = purchase_unit_price.get_int();
			p.count = purchase_count.get_int();
		}
		else
			error("Unit price & count should be positive numbers");

		temp->purchases.push_back(p);
	}
	else
		error("Please add an order first");
}

void Order_window::cb_add_order(Address, Address pw)
{
	reference_to<Order_window>(pw).order();
}

void Order_window::cb_add_purchase(Address, Address pw)
{
	reference_to<Order_window>(pw).purchase();
}

void Order_window::cb_quit(Address, Address pw)
{
	reference_to<Order_window>(pw).quit();
}

void Order_window::quit()
{
	hide();
}

void Order_window::cb_next(Address, Address pw)
{
	reference_to<Order_window>(pw).next();
}

void Order_window::next()
{
	if (!file_loaded) {
		ofs.open(output_file.get_string());
		output_display.put(output_file.get_string());
		file_loaded = true;
	}
	else {
		ofs.close();
		output_display.put("");
		file_loaded = false;
	}
	
	change_display(file_loaded);
	redraw();
}

int main()
try {
	Order_window win{ Point{ 100, 100 }, 600, 400, "Orders" };
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