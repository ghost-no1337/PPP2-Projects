#include "../../std_lib_facilities.h"

int main()
{
	int birth_year{ 2001 };
	cout << showbase << birth_year << "(decimal)" << '\t'
		<< hex << birth_year << "(hexadecimal)" << '\t'
		<< oct << birth_year << "(octal)" << '\n';

	cout << dec << 16 << '\n';

	int a, b, c, d;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

	cout << 1234567.89 << '\t'
		<< fixed << 1234567.89 << '\t'
		<< scientific << 1234567.89 << '\n';

	cout << setw(9) << "Junqi" << '|' << setw(4) << "Xie" << '|'
		<< setw(11) << 15221034020 << '|' << "junqi_xie@outlook.com" << '\n';
	cout << setw(9) << "Hong" << '|' << setw(4) << "Liu" << '|'
		<< setw(11) << 13611649471 << '|' << "cy755hq411@163.com" << '\n';
	cout << setw(9) << "Chongqing" << '|' << setw(4) << "Xie" << '|'
		<< setw(11) << 13916830579 << '|' << "vipxie365@163.com" << '\n';

	keep_window_open();
	return 0;
}