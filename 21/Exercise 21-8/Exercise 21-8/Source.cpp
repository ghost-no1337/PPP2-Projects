#include "../../std_lib_facilities.h"
#include <map>

struct Sort_words {
	bool operator()(pair<string, int> p1, pair<string, int> p2) {
		if (p1.second == p2.second)
			return p1.first > p2.first;
		return p1.second > p2.second;
	}
};

int main()
{
	map<string, int> words;

	for (string s; cin >> s; )
		++words[s];

	vector<pair<string, int>> sorted_words{ words.begin(), words.end() };

	sort(sorted_words, Sort_words());
	for (const auto& p : sorted_words)
		cout << p.second << ": " << p.first << '\n';

	keep_window_open();
}