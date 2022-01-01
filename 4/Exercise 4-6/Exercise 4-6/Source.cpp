#include "../../std_lib_facilities.h"

vector<string> numbers = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int get_number()
{
	int val = -1;
	if (cin >> val)
		return val;
	cin.clear();
	string s;
	cin >> s;
	for (int i = 0; i < numbers.size(); ++i)
		if (numbers[i] == s) 
			val = i;
	return val;
}

int main()
{
	int val1 = get_number();
	char operation = 0;
	cin >> operation;
	int val2 = get_number();
	if (val1 == -1 || val2 == -1)
		simple_error("fail to read the number");

	string hint;
	double result;

	switch (operation) {
	case '+':
		hint = "sum of ";
		result = val1 + val2;
		break;
	case '-':
		hint = "difference between ";
		result = val1 - val2;
		break;
	case '*':
		hint = "product of ";
		result = val1*val2;
		break;
	case '/':
		hint = "ratio of ";
		hint = val1 / val2;
		break;
	default:
		simple_error("Not an operator I know");
	}
	cout << "The " << hint << val1 << " and " << val2 << " is " << result << ".\n";
	keep_window_open();
	return 0;
}