#include "../../std_lib_facilities.h"

typedef vector<char> Line;

class Text_iterator {
	list<Line>::iterator ln;
	Line::iterator pos;
public:
	Text_iterator(list<Line>::iterator ll, Line::iterator pp)
		:ln{ ll }, pos{ pp } { }

	list<Line>::iterator line() const { return ln; }
	Line::iterator position() const { return pos; }

	char& operator*() { return *pos; }
	Text_iterator& operator++();
	Text_iterator& operator--();

	bool operator==(const Text_iterator& other) const
	{
		return ln == other.ln && pos == other.pos;
	}
	bool operator!=(const Text_iterator& other) const
	{
		return !(*this == other);
	}
};

Text_iterator& Text_iterator::operator++()
{
	++pos;
	if (pos == (*ln).end()) {
		++ln;
		pos = (*ln).begin();
	}
	return *this;
}

Text_iterator& Text_iterator::operator--()
{
	if (pos == (*ln).begin()) {
		--ln;
		pos = (*ln).end();
	}
	--pos;
	return *this;
}

struct Document {
	list<Line> line;

	Text_iterator begin()
	{
		return Text_iterator(line.begin(), (*line.begin()).begin());
	}
	Text_iterator end()
	{
		auto last = line.end();
		--last;
		return Text_iterator(last, (*last).end());
	}
};

void print(Document& d)
{
	for (auto p : d) cout << p;
}

void erase_line(Document& d, int n)
{
	if (n < 0 || d.line.size() - 1 <= n) return;
	auto p = d.line.begin();
	advance(p, n);
	d.line.erase(p);
}

template<typename Iter>
void advance(Iter& p, int n)
{
	while (0<n) { ++p; --n; }
}


bool match(Text_iterator first, Text_iterator last, const string& s)
{
	string::const_iterator p;

	for (p = s.begin();
		p != s.end() && first != last && *p == *first;
		++p, ++first)
	{
	}

	return p == s.end();
}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s)
{
	if (s.size() == 0) return last;
	char first_char = s[0];
	while (true) {
		auto p = find(first, last, first_char);
		if (p == last || match(p, last, s)) return p;
		first = ++p;
	}
}

void replace(Text_iterator first, Text_iterator last, const string& to_find, const string& to_replace)
{
	auto p = find_txt(first, last, to_find);
	for (int i = 0; i < to_find.size(); ++i) {
		(*(p.line())).erase(p.position());
		++p;
	}

	for (int i = 0; i < to_replace.size(); ++i) {
		(*(p.line())).insert(p.position(), to_replace[i]);
		++p;
	}
}

int count_char(Document& d)
{
	int sum = 0;
	for (auto x : d.line)
		sum += x.size();
	return sum;
}

bool is_whitespace(char ch, const string& whitespace)
{
	for (char wh : whitespace)
		if (ch == wh)
			return true;
}

int count_word(Document& d, const string& whitespace)
{
	int sum = 1;
	for (auto p = d.begin(); p != d.end(); ++p)
		if (is_whitespace(*p, whitespace)) {
			++p;
			if (is_whitespace(*p, whitespace))
				--p;
			else
				++sum;
		}
	return sum;
}

int main()
{
	Document my_doc;
	//do something

	keep_window_open();
}