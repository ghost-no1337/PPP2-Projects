#include "../../std_lib_facilities.h"

int main()
{
	double val1 = 0, val2 = 0;
	char operation = 0;
	cin >> val1 >> operation >> val2;

	string hint;
	double result = 0;
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
		result = val1 * val2;
		break;
	case '/':
		hint = "ratio of ";
		result = val1 / val2;
		break;
	default:
		simple_error("Not an operator I know.");
	}
	cout << "The " << hint << val1 << " and " << val2 << " is " << result << ".\n";
	keep_window_open();
	return 0;
}