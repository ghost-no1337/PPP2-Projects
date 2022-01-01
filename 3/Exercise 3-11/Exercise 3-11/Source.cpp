#include "../../std_lib_facilities.h"

int main()
{   //input parts
	cout << "This program enables you to know the amount of coins you have in all.\n";

	cout << "How many pennies do you have?";
	int penny = 0;
	cin >> penny;
	if (penny < 0)
		simple_error("no negative pennies.");

	cout << "How many nickels do you have?";
	int nickel = 0;
	cin >> nickel;
	if (nickel < 0)
		simple_error("no negative nickels.");

	cout << "How many dimes do you have?";
	int dime = 0;
	cin >> dime;
	if (dime < 0)
		simple_error("no negative dimes.");

	cout << "How many quarters do you have?";
	int quarter = 0;
	cin >> quarter;
	if (quarter < 0)
		simple_error("no negative quarters.");

	cout << "How many half dollars do you have?";
	int half_dollar = 0;
	cin >> half_dollar;
	if (half_dollar < 0)
		simple_error("no negative half dollars.");

	cout << "How many dollars do you have?";
	int dollar = 0;
	cin >> dollar;
	if (dollar < 0)
		simple_error("no negative dollars.");
	
	//output parts
	if (penny == 1)
		cout << "\nYou have 1 penny.\n";
	else
		cout << "\nYou have " << penny << " pennies.\n";

	if (nickel == 1) {
		cout << "You have 1 nickel.\n";
	}
	else {
		cout << "You have " << nickel << " nickels.\n";
	}

	if (dime == 1) {
		cout << "You have 1 dime.\n";
	}
	else {
		cout << "You have " << dime << " dimes.\n";
	}

	if (quarter == 1) {
		cout << "You have 1 quarter.\n";
	}
	else {
		cout << "You have " << quarter << " quarters.\n";
	}

	if (half_dollar == 1) {
		cout << "You have 1 half dollar.\n";
	}
	else {
		cout << "You have " << half_dollar << " half dollars.\n";
	}

	if (dollar == 1) {
		cout << "You have 1 dollar.\n";
	}
	else {
		cout << "You have " << dollar << " dollars.\n";
	}

	//calculate the amount
	double result = penny + nickel * 5 + dime * 10 + quarter * 25 + half_dollar * 50 + dollar * 100;
	result /= 100;
	cout << "The value of all of your coins is $" << result << ".\n";

	keep_window_open();
}