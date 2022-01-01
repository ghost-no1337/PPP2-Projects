#include "../../std_lib_facilities.h"	

vector<string> nouns = { "birds", "fish", "C++" };
vector<string> verbs = { "rules", "fly", "swim" };
vector<string> conjunctions = { "and", "or", "but" };

bool noun(string word)
{
	for (int i = 0; i < nouns.size(); ++i)
		if (word == nouns[i])
			return true;
	return false;
}

bool verb(string word)
{
	for (int i = 0; i < verbs.size(); ++i)
		if (word == verbs[i])
			return true;
	return false;
}

bool conj(string word)
{
	for (int i = 0; i < conjunctions.size(); ++i)
		if (word == conjunctions[i])
			return true;
	return false;
}

bool sentence()
{
	string word;
	cin >> word;
	if (!noun(word)) 
		return false;

	cin >> word;
	if (!verb(word)) 
		return false;

	cin >> word;
	if (word == ".") 
		return true;
	if (!conj(word))
		return false;
	return sentence();
}

int main()
try {
	cout << "Enter a sentence of the simplified grammar (terminated by a dot):\n";

	while (cin) {
		if (sentence())
			cout << "OK\n";
		else
			cout << "not OK\n";
		cout << "Try again: ";
	}

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cout << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cout << "error: unknown error\n";
	keep_window_open();
	return -1;
}