#include "../../std_lib_facilities.h"

class Int
{
public:
	string output;
	int value = 0;
	string form = "decimal";
	void fromstring(string s);
};

string chooseform(string s)
{
	switch (s[0]) {
	case '0':
		switch (s[1]) {
		case 'x':
			return "hexadecimal";
		default:
			break;
		}
		return "octal";
	default:
		return "decimal";
	}
}

void Int::fromstring(string s)
{
	output = s;
	form = chooseform(s);

	stringstream ss{ s };
	if (form == "decimal")
		ss >> dec >> value;
	else if (form == "hexadecimal")
		ss >> hex >> value;
	else if (form == "octal")
		ss >> oct >> value;
	if (!ss)
		error("bad input integer");
}

int main()
try {
	vector<Int> Ints;

	cout << "Please enter several integers (enter 'end' to end):\n";
	for (string s; cin >> s; ) {
		if (s == "end")
			break;
		Int I;
		I.fromstring(s);
		Ints.push_back(I);
	}

	for (Int I : Ints)
		cout << setw(4) << I.output << ' ' << setw(11) << I.form 
		<< " converts to " << setw(3) << I.value << " decimal.\n";

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open("~~");
	return -1;
}