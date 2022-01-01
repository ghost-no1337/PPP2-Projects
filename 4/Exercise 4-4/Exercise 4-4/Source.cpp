#include "../../std_lib_facilities.h"

int main()
{
	int target = 0;
	cout << "Your number: ";
	cin >> target;

	int smallest = 1;
	int largest = 100;
	int result = 50;
	if (target < 1 || target > 100)
		simple_error("input number out of range");

	while (result != target) {
		char response = 0;
		cout << "Is the number you are thinking of less than " << result << "? (Please answer by 'y' and 'n')\n";
		cin >> response;
		switch (response) {
		case 'y':
			largest = result;
			break;
		case 'n':
			smallest = result - 1;
			break;
		default:
			simple_error("not an expected response");
		}
		result = (largest + smallest) / 2 + 1;

		if (largest < target || smallest > target)
			simple_error("you cheated");
	}
	cout << "Your number is " << result << ".\n";

	keep_window_open();
	return 0;
}