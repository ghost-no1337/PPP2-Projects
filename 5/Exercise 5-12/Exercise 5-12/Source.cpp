#include "../../std_lib_facilities.h"

//modified as Exercise 6-8
void check(vector<char> x)
{
	sort(x);
	if (x.size() != 4)
		error("not 4 letters.");
	for (int i = 1; i < x.size(); ++i)
		if (x[i] == x[i - 1])
			error("repeated letters.\nPlease restart the game");
}

int main()
try {
	cout << "Let's play 'Bulls and Cows' games!\n";
	vector<char> given_letters;
	int result = 0;

	for (int i = 0; i < 4; ++i)	{
		int x = randint(26);
		given_letters.push_back(char(x + 'A'));
	}
	check(given_letters);

	while (result == 0)	{
		vector<char> answer;
		int bull = 0, cow = 0;

		cout << "Your tern: ";
		char c;
		cin >> c;
		while (c != '|') {
			answer.push_back(c);
		}

		check(answer);

		if (answer == given_letters) {
			result = 1;
			cout << "You win!\n";
		}
		else {
			for (int i = 0; i < 4; ++i)	{
				if (answer[i] == given_letters[i])
					++bull;
				else {
					for (int x : given_letters)
						if (answer[i] = x)
							++cow;
				}
			}
			cout << "Bull: " << bull << ", Cows: " << cow << '\n';
		}
	}

	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << ".\n";
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error.\n";
	keep_window_open();
	return -1;
}