/*
	Project Name: Roman int Calculator

	Parts:
		Roman_int
		Token & Token_stream
		Variable & Symbol_table
		Calculate
		Main

	Grammar:
		Calculation:
		Statement
		Print
		Quit
		Help
		Calculation Statement

	Statement:
		Declaration
		Expression

	Declaration:
		"let"   Name "=" Expression
		"const" Name "=" Expression

	Print:
		enter / ";"

	Quit:
		"quit"

	Help:
		"help"

	Expression:
		Term
		Expression "+" Term
		Expression "-" Term
	Term:
		Primary
		Term "*" Primary
		Term "/" Primary
		Term "%" Primary
	Primary:
		Number
		Name
		"(" Expression ")"
*/

#include "../../std_lib_facilities.h"

const char number = '8'; // '8' represents numbers
const char name = 'A'; // 'A' represents names of variables
const char quit = 'Q';
const char print = ';';
const char let = 'L';
const char const_ch = 'C';
const string declkey = "let";
const string constkey = "const";
const string prompt = "> ";
const string result = "= ";

void help_doc()
{
	cout << "HELP DOCUMENT:\n"
		<< "NOTICE: This edition of calculator only accepts Roman ints.\n"
		<< "        Range of Roman int is (0, 4000). Both input and output.\n"
		<< "        The result may be not accurate.\n"
		<< "Calculate:\n"
		<< "\t'+', '-', '*', '/' '%'(int only): calculate.\n"
		<< "\t'(', ')':                         mark prority\n"
		<< "Variables:\n"
		<< "\t''let' name '=' value':           define vriables\n"
		<< "\t''const' name '=' value':         define const variables\n"
		<< "\t'name '=' value':                 alter variables\n"
		<< "Basic functions:\n"
		<< "\tenter / ';':                      calculate*\n"
		<< "\t'quit':                           quit\n"
		<< "\t'help':                           view this help document\n"
		<< "\t*  When there is an error, use ';' only.";
}

// Roman_int part:

class Roman_int
{
public:
	int I = 0;
	int V = 0;
	int X = 0;
	int L = 0;
	int C = 0;
	int D = 0;
	int M = 0;
	int as_int() const;
};

int Roman_int::as_int() const
{
	return 1 * I + 5 * V + 10 * X + 50 * L + 100 * C + 500 * D + 1000 * M;
}

int to_int(string s)
{
	Roman_int r;
	for (int i = 0; i < s.size(); ++i) {
		switch (s[i]) {
		case 'M':
			++r.M;
			break;
		case 'D':
			++r.D;
			break;
		case 'C':
			if (i != s.size() && (s[i + 1] == 'M' || s[i + 1] == 'D'))
				--r.C;
			else
				++r.C;
			break;
		case 'L':
			++r.L;
			break;
		case 'X':
			if (i != s.size() && (s[i + 1] == 'C' || s[i + 1] == 'L'))
				--r.X;
			else
				++r.X;
			break;
		case 'V':
			++r.V;
			break;
		case 'I':
			if (i != s.size() && (s[i + 1] == 'X' || s[i + 1] == 'V'))
				--r.I;
			else
				++r.I;
			break;
		}
	}
	if (r.as_int() <= 0 || r.as_int() >= 4000)
		error("input out of range");
	return r.as_int();
}

string to_Roman(int temp)
{
	if (temp <= 0 || temp >= 4000)
		error("output out of range");

	string s = "";
	while (true) {
		if (temp >= 1000) {
			s += 'M';
			temp -= 1000;
		}
		else if (temp >= 900) {
			s += "CM";
			temp -= 900;
		}
		else if (temp >= 500) {
			s += 'D';
			temp -= 500;
		}
		else if (temp >= 400) {
			s += "CD";
			temp -= 400;
		}
		else if (temp >= 100) {
			s += 'C';
			temp -= 100;
		}
		else if (temp >= 90) {
			s += "XC";
			temp -= 90;
		}
		else if (temp >= 50) {
			s += 'L';
			temp -= 50;
		}
		else if (temp >= 40) {
			s += "XL";
			temp -= 40;
		}
		else if (temp >= 10) {
			s += 'X';
			temp -= 10;
		}
		else if (temp >= 9) {
			s += "IX";
			temp -= 9;
		}
		else if (temp >= 5) {
			s += 'V';
			temp -= 5;
		}
		else if (temp >= 4) {
			s += "IV";
			temp -= 4;
		}
		else if (temp >= 1) {
			s += 'I';
			temp -= 1;
		}
		else
			return s;
	}
}

// Token & Token_stream part:

class Token {
public:
	char kind;
	double value;
	string name;
	Roman_int roman;
	Token(char ch) : kind(ch), value(0) {}
	Token(char ch, double val) : kind(ch), value(val) {}
	Token(char ch, string n) : kind(ch), name(n) {}
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream()
	:full(false), buffer(0)
{
}

void Token_stream::putback(Token t)
{
	if (full)
		error("putback() into a full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	while (true) {
		char ch;
		cin.get(ch);

		switch (ch) {
		case '\n': case ';':
			return Token(print);
		case '(': case ')': case '=':
		case '+': case '-': case '*': case '/': case '%':
			return Token(ch); // ch represents itself
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			error("accepts Roman ints only");
		}
		case 'I': case 'V': case 'X': case'L': case 'C':
		case 'D': case 'M':
		{
			cin.putback(ch);
			string s;
			cin >> s;
			return Token(number, to_int(s));
		}
		default:
			if (isalpha(ch)) {
				string s;
				s += ch;
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
					s += ch;
				cin.putback(ch);
				if (s == declkey)
					return Token(let);
				if (s == constkey)
					return Token(const_ch);
				if (s == "quit")
					return Token(quit);
				if (s == "help") {
					help_doc();
					return Token(print);
				}
				return Token(name, s);
			}
			else if (!isspace(ch))
				error("Bad token");
		}
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch = 0;
	while (cin >> ch)
		if (ch == c)
			return;
}

Token_stream ts;

// Variable & Symbol_table part:

class Variable {
public:
	string name;
	double value;
	bool source; // true for const, false for common
	Variable(string n, double v, bool b) :name(n), value(v), source(b) { }
};

class Symbol_table {
public:
	vector<Variable> var_table;
	double get_value(string s);
	void set_value(string s, double d);
	bool is_declared(string var);
	double define_name(string s, double val, bool source);
};

double Symbol_table::get_value(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s)
			return var_table[i].value;
	error("get: undefined variable ", s);
}

void Symbol_table::set_value(string s, double d)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) {
			if (var_table[i].source)
				error(s, " is a const");
			var_table[i].value = d;
			return;
		}
	error("set: undefined variable ", s);
}

bool Symbol_table::is_declared(string var)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == var)
			return true;
	return false;
}

double Symbol_table::define_name(string s, double val, bool source)
{
	if (is_declared(s))
		error(s, " declared twice");
	var_table.push_back(Variable(s, val, source));
	return val;
}

Symbol_table st;

// Calculate part:

int accurate(double d)
{
	int i = int(d);
	if (d - i >= 0.5)
		return i + 1;
	else
		return i;
}

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			error("')' expected");
		return d;
	}
	case number:
		return t.value;
	case name:
	{
		Token next = ts.get();
		if (next.kind == '=') {
			double d = expression();
			st.set_value(t.name, d);
			return d;
		}
		else {
			ts.putback(next);
			return st.get_value(t.name);
		}
	}
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0)
				error("divide by zero");
			left = accurate(left / d);
			t = ts.get();
			break;
		}
		case '%':
		{
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(term());
			if (i2 == 0)
				error("%: divide by zero");
			left = i1%i2;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration(Token t)
{
	Token t1 = ts.get();
	if (t1.kind != name)
		error("name expected in declaration");
	string var_name = t1.name;

	Token t2 = ts.get();
	if (t2.kind != '=')
		error("= missing in declaration of ", var_name);

	double d = expression();
	st.define_name(var_name, d, t.kind == const_ch);
	return d;
}

string statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
	case const_ch:
		return to_Roman(declaration(t.kind));
	default:
		ts.putback(t);
		return to_Roman(expression());
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

void calculate()
{
	while (cin)
		try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print)
			t = ts.get();
		if (t.kind == quit)
			return;
		ts.putback(t);
		cout << result << statement() << '\n';
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		clean_up_mess();
	}
}

// Main:

int main()
try {
	help_doc();

	cout << '\n';
	calculate();

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "exception \n";
	keep_window_open("~~");
	return -1;
}