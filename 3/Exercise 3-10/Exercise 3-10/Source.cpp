#include"../../std_lib_facilities.h"

int main()
{
	cout << "Type [operations i.e.'+'] [number1] [number2]: ";
	string operation;
	double number1 = 0;
	double number2 = 0;
	double result = 0;
	cin >> operation >> number1 >> number2;

	if (operation == "+" || operation == "plus")
		result = number1 + number2;
	else if (operation == "-" || operation == "minus")
		result = number1 - number2;
	else if (operation == "*" || operation == "mul")
		result = number1 * number2;
	else if (operation == "/" || operation == "div")
		result = number1 / number2;

	cout << result << '\n';
	keep_window_open();
}