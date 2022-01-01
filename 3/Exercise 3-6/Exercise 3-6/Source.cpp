#include "../../std_lib_facilities.h"

int main()
{
	cout << "Type in 3 names: ";
	string a = "0";
	string b = "0";
	string c = "0";
	cin >> a >> b >> c;

	if (a <= b && a <= c) {
		if (b <= c) {
			cout << a << ", " << b << ", " << c << ".\n";
		}
		else if (c <= b){
			cout << a << ", " << c << ", " << b << ".\n"; 
		}
	}
	else if (b <= a && b <= c) {
		if (a <= c) {
			cout << b << ", " << a << ", " << c << ".\n";
		}
		else if (c <= a) {
			cout << b << ", " << c << ", " << a << ".\n";
		}
	}
	else if (c <= a && c <= b) {
		if (a <= b) {
			cout << c << ", " << a << ", " << b << ".\n";
		}
		else if (b <= a) {
			cout << c << ", " << b << ", " << a << ".\n";
		}
	}

	keep_window_open();
}