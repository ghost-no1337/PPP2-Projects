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

bool operator<(God& g1, God& g2)
{
	return g1.name < g2.name;
}

bool operator<=(God& g1, God& g2)
{
	return g1.name <= g2.name;
}

bool operator>(God& g1, God& g2)
{
	return g1.name > g2.name;
}

bool operator>=(God& g1, God& g2)
{
	return g1.name >= g2.name;
}

bool operator==(const God& g1, const God& g2)
{
	return g1.name == g2.name;
}

template <typename T>
class Link {
public:
    T value;

    Link(const T &v, Link<T> *p = nullptr, Link<T> *s = nullptr)
        : value{v}, prev{p}, succ{s} {}

    Link<T> *insert(Link<T> *n);
    Link<T> *add(Link<T> *n);
    Link<T> *add_ordered(Link<T> *n);
    Link<T> *erase();
    Link<T> *find(const T &t);
    const Link<T> *find(const T &t) const;

    Link<T> *advance(int n) const;

    Link<T> *next() const { return succ; }
    Link<T> *previous() const { return prev; }
private:
    Link<T> *prev;
    Link<T> *succ;
};

template <typename T>
Link<T> *Link<T>::insert(Link<T> *n)
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

template <typename T>
Link<T> *Link<T>::add(Link<T> *n)
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

template <typename T>
Link<T> *Link<T>::add_ordered(Link<T> *n)
{
	if (n == nullptr) 
		return this;
	if (this == nullptr) {
		n->succ = nullptr;
		n->prev = nullptr;
		return n;
	}

	if (n->value < value) {
		Link<T>* p = insert(n);
		return p;
	}

	Link<T>* p = this;
	while (n->value >= p->value) {
		if (p->succ == nullptr) {
			p->add(n);
			return this;
		}
		p = p->succ;
	}

	p->insert(n);
	return this;
}

template <typename T>
Link<T> *Link<T>::erase()
{
    if (this == nullptr)
        return nullptr;
    if (succ)
        succ->prev = prev;
    if (prev)
        prev->succ = succ;
    return succ;
}

template <typename T>
Link<T> *Link<T>::find(const T &t)
{
    Link<T> *p = this;
    while (p) {
        if (p->value == t)
            return p;
        p = p->succ;
    }
    return nullptr;
}

template <typename T>
Link<T> *Link<T>::advance(int n) const
{
    Link<T> *p = const_cast<Link<T> *>(this);
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

template <typename T>
void print_all(Link<T> *p)
{
    cout << "{ ";
    while (p) {
        cout << p->value;
        if (p = p->next())
            cout << ",\n";
    }
    cout << " }\n";
}

template <typename T>
Link<T>* extract(Link<T>* l, const T &t) 
{
	Link<T>* p = l->find(t);
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
	Link<God> *gods = new Link<God>{ God{ "Thor", "Norse", "", ""} };
	gods = gods->insert(new Link<God>{ God{ "Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir"} });
	gods = gods->insert(new Link<God>{ God{ "Zeus", "Greek", "", "lightning"} });
	gods = gods->insert(new Link<God>{ God{ "Freia", "Norse", "", "" } });
	gods = gods->insert(new Link<God>{ God{ "Hera", "Greek", "", "" } });
    gods = gods->insert(new Link<God>{ God{ "Athena", "Greek", "", "" } });
    gods = gods->insert(new Link<God>{ God{ "Ares", "Greek", "", "" } });
    gods = gods->insert(new Link<God>{ God{ "Poseidon", "Greek", "", "" } });

	print_all(gods);
    
	Link<God>* norse_gods = nullptr;
	norse_gods = norse_gods->add_ordered(extract(gods, God{ "Thor", "Norse", "", "" }));
	norse_gods = norse_gods->add_ordered(extract(gods, God{ "Odin", "Norse", "Eight-legged flying horse called Sleipner", "Spear called Gungnir" }));
	norse_gods = norse_gods->add_ordered(extract(gods, God{ "Freia", "Norse", "", "" }));

	Link<God>* greek_gods = nullptr;
	greek_gods = greek_gods->add_ordered(extract(gods, God{ "Zeus", "Greek", "", "lightning" }));
	greek_gods = greek_gods->add_ordered(extract(gods, God{ "Hera", "Greek", "", "" }));
	greek_gods = greek_gods->add_ordered(extract(gods, God{ "Athena", "Greek", "", "" }));
	greek_gods = greek_gods->add_ordered(extract(gods, God{ "Ares", "Greek", "", "" }));
	greek_gods = greek_gods->add_ordered(extract(gods, God{ "Poseidon", "Greek", "", "" }));

    print_all(norse_gods);
    print_all(greek_gods);
    
    keep_window_open();
}
catch (exception &e) {
	cerr << e.what() << '\n';
	keep_window_open();
}