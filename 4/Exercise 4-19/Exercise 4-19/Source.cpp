# include "../../std_lib_facilities.h"

//modified as Exercise 6-4

class Name_value {
public:
	string name;
	int score;
};

int main()
try {
	vector<Name_value> scores;

	for (Name_value score; cin >> score.name >> score.score && score.name != "NoName"; ) {
		for (int i = 0; i < scores.size(); ++i)
			if (score.name == scores[i].name)
				error("No repitation!");
		scores.push_back(score);
	}

	cout << "\nThe results:\n";
	for (int i = 0; i < scores.size(); ++i) {
		cout << "( " << scores[i].name << ", " << scores[i].score << " )\n";
	}

	Name_value search;
	cout << "\nType the name of the person you want to check: ";
	cin >> search.name;
	for (int i = 0; i < scores.size(); ++i) {
		if(search.name == scores[i].name)
			cout << "His/her score is " << scores[i].score << ".\n";
	}

	cout << "\nType the score you want to check: ";
	cin >> search.score;
	vector<string> score_check;
	for (int i = 0; i < scores.size(); ++i) {
		if (search.score == scores[i].score)
			score_check.push_back(scores[i].name);
	}
	cout << "The one who has the score is ";
	for (int i = 0; i < score_check.size(); ++i) {
		cout <<score_check[i] << ", ";
	}
	cout << '\n';
	keep_window_open();
	return 0;
}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "error: unknown error\n";
	keep_window_open();
	return -1;
}