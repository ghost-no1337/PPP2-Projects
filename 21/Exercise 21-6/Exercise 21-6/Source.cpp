#include "../../std_lib_facilities.h"
#include <set>

struct Fruit {
	string name;
	int count;
	double unit_price;
	// Date last_sale_date;
};

struct Fruit_comparison {
	bool operator()(const Fruit* a, const Fruit* b) const
	{
		return a->name < b->name;
	}
};

ostream& operator<<(ostream& os, const Fruit& f)
{
	return os << "{ " << f.name << ", " << f.count << ", " << f.unit_price << " }";
}

int main()
{
	set<Fruit*, Fruit_comparison> inventory;

	inventory.insert(new Fruit{ "quince", 5 });
	inventory.insert(new Fruit{ "apple", 200, 0.37 });

	for (const auto& x : inventory)
		cout << *x << '\n';

	keep_window_open();
}