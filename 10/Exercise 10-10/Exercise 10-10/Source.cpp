/*
	Project Name: Calculator

	Parts:
		Token & Token_stream
		Variable & Symbol_table
		File input & output
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
	"-" Primary
	"+" Primary
*/

#include "../../std_lib_facilities.h"

const char number = '8'; // '8' represents numbers
const char name = 'A'; // 'A' represents names of variables
const char quit = 'Q';
const char print = ';';
const char let = 'L';
const char const_ch = 'C';
const char from = 'F';
const char to = 'T';
const char file_quit = 'E'; // 'E' represents file quit
const string declkey = "let";
const string constkey = "const";
const string fromkey = "from";
const string tokey = "to";
const string prompt = "> ";
const string result = "= ";
bool use_file = false;
ifstream ist;
ofstream ost;

void help_doc()
{
	cout << "HELP DOCUMENT:\n"
		<< "Calculate:\n"
		<< "\t'+', '-', '*', '/' '%'(int only): calculate\n"
		<< "\t'(', ')':                         mark prority\n"
		<< "Variables:\n"
		<< "\t''let' name '=' value':           define vriables\n"
		<< "\t''const' name '=' value':         define const variables\n"
		<< "\t'name '=' value':                 alter variables\n"
		<< "File input and output:\n"
		<< "\t''from' input 'to' output':       choose input and output file\n"
		<< "\t                                  0 will be shown if succeed\n"
		<< "\t* Please add ';' at the end of statement, 'quit' at the end of file.\n"
		<< "\t  No suffix required.\n"
		<< "Basic functions:\n"
		<< "\tenter / ';':                      calculate*\n"
		<< "\t'quit':                           quit\n"
		<< "\t'help':                           view this help document\n"
		<< "\t*  When there is an error, use ';' only.";
}

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

	while (use_file) {
		char ch;
		ist.get(ch);

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
			ist.putback(ch);
			double val;
			ist >> val;
			return Token(number, val);
		}
		default:
			if (isalpha(ch)) {
				string s;
				s += ch;
				while (ist.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
					s += ch;
				ist.putback(ch);
				if (s == declkey)
					return Token(let);
				if (s == constkey)
					return Token(const_ch);
				if (s == fromkey || s == tokey)
					error("no effect in file mode");
				if (s == "quit")
					return Token(file_quit);
				return Token(name, s);
			}
			else if (!isspace(ch))
				error("Bad token");
		}
	}

	while (!use_file) {
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
			return Token(number, val);
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
				if (s == fromkey)
					return Token(from);
				if (s == tokey)
					return Token(to);
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
	if (use_file) {
		if (full && c == buffer.kind) {
			full = false;
			return;
		}
		full = false;

		char ch = 0;
		while (ist >> ch)
			if (ch == c)
				return;
	}
	if (!use_file) {
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

// File input and output part:

void load_file()
{
	Token t1 = ts.get();
	if (t1.kind != name)
		error("file name expected");
	ist.open(t1.name);
	if (!ist)
		error("can't open input file");

	Token t2 = ts.get();
	if (t2.kind != to)
		error("output file missing");

	Token t3 = ts.get();
	if (t3.kind != name)
		error("file name expected");
	ost.open(t3.name);
	if (!ost)
		error("can't open output file");

	use_file = true;
}

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
	case from:
		load_file();
		return 0;
	case file_quit:
		ist.close();
		ost.close();
		use_file = false;
		return 0;
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

void calculate()
{
	while (true) {
		while (use_file)
		try {
			Token t = ts.get();
			while (t.kind == print)
				t = ts.get();
			if (t.kind == quit)
				return;
			ts.putback(t);
			ost << statement() << '\n';
			}
		catch (exception &e) {
			ost << e.what() << '\n';
			clean_up_mess();
		}
		while (!use_file) 
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
		catch (exception &e) {
			cerr << e.what() << '\n';
			clean_up_mess();
		}
	}
}

// Main:

int main()
try {
	help_doc();
	st.define_name("pi", 3.1415926535, true);
	st.define_name("e", 2.7182818284, true);

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