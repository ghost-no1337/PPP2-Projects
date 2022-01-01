#include "../../std_lib_facilities.h"

struct God {
    string name;
    string mythology;
    string vehicle;
    string weapon;

    God(const string &n, const string &m = "", const string &v = "", const string &w = "")
        : name{n}, mythology{m}, vehicle{v}, weapon{w} {}
};

ostream& operator<<(ostream &os, God &g)
{
    os << g.name << '\t' << g.mythology << '\t' << g.vehicle << '\t' << g.weapon;
    return os;
}

class Link {
public:
    God value;

    Link(const string &v, Link *p = nullptr, Link *s = nullptr)
        : value{v}, prev{p}, succ{s} {}
    Link(const God &g, Link *p = nullptr, Link *s = nullptr)
        : value{g}, prev{p}, succ{s} {}

    Link *insert(Link *n);
    Link *add(Link *n);
    Link *add_ordered(Link *n);
    Link *erase();
    Link *find(const string &s);
    const Link *find(const string &s) const;

    Link *advance(int n) const;

    Link *next() const { return succ; }
    Link *previous() const { return prev; }
private:
    Link *prev;
    Link *succ;
};

Link *Link::insert(Link *n)
{
    if (n == nullptr)
        return this;
    if (this == nullptr)
        return n;
    n->succ = this;
    if (prev)
        prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

Link *Link::add(Link *n)
{
    if (n == nullptr)
        return this;
    if (this == nullptr)
        return n;
    n->prev = this;
    if (succ)
        succ->prev = n;
    n->succ = succ;
    succ = n;
    return n;
}

Link *Link::add_ordered(Link *n)
{
	if (n == nullptr) 
		return this;
	if (this == nullptr) {
		n->succ = nullptr;
		n->prev = nullptr;
		return n;
	}

	if (n->value.name < value.name) {
		Link* p = insert(n);
		return p;
	}

	Link* p = this;
	while (n->value.name >= p->value.name) {
		if (p->succ == nullptr) {
			p->add(n);
			return this;
		}
		p = p->succ;
	}

	p->insert(n);
	return this;
}

Link *Link::erase()
{
    if (this == nullptr)
        return nullptr;
    if (succ)
        succ->prev = prev;
    if (prev)
        prev->succ = succ;
    return succ;
}

Link *Link::find(const string &s)
{
    Link *p = this;
    while (p) {
        if (p->value.name == s)
            return p;
        p = p->succ;
    }
    return nullptr;
}

Link *Link::advance(int n) const
{
    Link *p = const_cast<Link *>(this);
    if (p == nullptr)
        return nullptr;
    if (0 < n) {
        while (n--) {
            if (p->succ == nullptr)
				return nullptr;
            p = p->succ;
        }
    }
    else if (n < 0) {
        while (n++) {
            if (p->prev == nullptr)
                return nullptr;
            p = p->prev;
        }
    }
    return p;
}

void print_all(Link *p)
{
    cout << "{ ";
    while (p) {
        cout << p->value;
        if (p = p->next())
            cout << ",\n";
    }
    cout << " }\n";
}

Link* extract(Link* l, string s) 
{
	Link* p = l->find(s);
	if (p) {
		if (p == l && p->next()) l = p->next();
		else l = nullptr;
		p->erase();
		return p;
	}
	return nullptr;
}

int main()
try {
	Link *gods = new Link{ God{ "Thor", "Norse", "", ""} };
	gods = gods->insert(new Link{ God{ "Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"} });
	gods = gods->insert(new Link{ God{ "Zeus", "Greek", "", "lightning"} });
	gods = gods->insert(new Link{ God{ "Freia", "Norse", "", "" } });
	gods = gods->insert(new Link{ God{ "Hera", "Greek", "", "" } });
    gods = gods->insert(new Link{ God{ "Athena", "Greek", "", "" } });
    gods = gods->insert(new Link{ God{ "Ares", "Greek", "", "" } });
    gods = gods->insert(new Link{ God{ "Poseidon", "Greek", "", "" } });

	print_all(gods);
    
	Link* norse_gods = nullptr;
	norse_gods = norse_gods->add_ordered(extract(gods, "Thor"));
	norse_gods = norse_gods->add_ordered(extract(gods, "Odin"));
	norse_gods = norse_gods->add_ordered(extract(gods, "Freia"));

	Link* greek_gods = nullptr;
	greek_gods = greek_gods->add_ordered(extract(gods, "Zeus"));
	greek_gods = greek_gods->add_ordered(extract(gods, "Hera"));
	greek_gods = greek_gods->add_ordered(extract(gods, "Athena"));
	greek_gods = greek_gods->add_ordered(extract(gods, "Ares"));
	greek_gods = greek_gods->add_ordered(extract(gods, "Poseidon"));

    print_all(norse_gods);
    print_all(greek_gods);
    
    keep_window_open();
}
catch (exception &e) {
	cerr << e.what() << '\n';
	keep_window_open();
}