#include "../../std_lib_facilities.h"

void print(const vector<double> &price, const vector<double> &weight)
{
	cout << '\n';
	for (int i = 0; i < price.size(); ++i)
		cout << price[i] << '\t' << weight[i] << ", \n";
}

void load_content(vector<double> &price, vector<double> &weight)
{
	double price_double = 0;
	double weight_double = 0;

	while (true) {
		cout << "price: ";
		cin >> price_double;
		if (price_double == 0)
			return;
		price.push_back(price_double);
		cout << "weight: ";
		cin >> weight_double;
		weight.push_back(weight_double);
	}
}

double index(const vector<double> &price, const vector<double> &weight)
{
	vector<double> index_vector;
	double result = 0;

	for (int i = 0; i < price.size(); ++i)
		index_vector.push_back(price[i] * weight[i]);

	for (double d : index_vector)
		result += d;

	return result;
}

int main()
{
	vector<double> price;
	vector<double> weight;

	load_content(price, weight);
	print(price, weight);

	cout << index(price, weight) << '\n';
	keep_window_open();
	return 0;
}