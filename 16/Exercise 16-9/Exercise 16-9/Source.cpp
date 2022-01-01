#include "../../GUI.h"
#include "../../Window.h"
#include "../../std_lib_facilities.h"

using namespace Graph_lib;

const char number = '8'; // '8' represents numbers
const char name = 'A'; // 'A' represents names of variables
const char let = 'L';
const char const_ch = 'C';
const string declkey = "let";
const string constkey = "const";
istringstream iss;
ostringstream oss;

// Token & Token_stream part:

class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch) : kind(ch), value(0) {}
	Token(char ch, double val) : kind(ch), value(val) {}
	Token(char ch, string n) : kind(ch), name(n) {}
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
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

	char ch;
	iss.get(ch);

	switch (ch) {
	case '(': case ')': case '=':
	case '+': case '-': case '*': case '/': case '%':
		return Token(ch); // ch represents itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		iss.putback(ch);
		double val;
		iss >> val;
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (iss.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
				s += ch;
			iss.putback(ch);
			if (s == declkey)
				return Token(let);
			if (s == constkey)
				return Token(const_ch);
			return Token(name, s);
		}
		else if (!isspace(ch))
			error("Bad token");
	}
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
	case '-':
		return -primary();
	case '+':
		return primary();
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
			left /= d;
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

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
	case const_ch:
		return declaration(t.kind);
	default:
		ts.putback(t);
		return expression();
	}
}

// GUI part:
struct Calculator : Window
{
	Calculator(Point xy, int w, int h, const string& title);
private:
	Button btn_calculate;
	In_box input;
	Out_box output;

	void calculate();

	static void cb_calculate(Address, Address);
};

Calculator::Calculator(Point xy, int w, int h, const string& title)
	:Window{ xy, w, h, title },
	btn_calculate{ Point{x_max() - 70, 0}, 70, 60, "Enter", cb_calculate },
	input{ Point{ x_max() - 300, 0 }, 100, 20, "Input:" },
	output{ Point{ x_max() - 300, 40 }, 100, 20, "Output:" }
{
	attach(btn_calculate);
	attach(input);
	attach(output);
	st.define_name("pi", 3.1415926535, true);
	st.define_name("e", 2.7182818284, true);
}

void Calculator::calculate()
try {
	iss.str(string(input.get_string()));
	if (input.get_string() == "")
		error("bad input: empty string");
	oss << statement();
	output.put(oss.str());
}
catch (exception &e) {
	cout << e.what() << '\n';
}

void Calculator::cb_calculate(Address, Address pw)
{
	reference_to<Calculator>(pw).calculate();
}

// Main:

int main()
try {
	Calculator win{ Point{ 100, 100 }, 600, 400, "Calculator" };
	return gui_main();
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