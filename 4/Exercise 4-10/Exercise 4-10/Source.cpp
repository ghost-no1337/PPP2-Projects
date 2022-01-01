#include "../../std_lib_facilities.h"

vector<string> prompt{ "rock", "scissors", "paper" };

int get_number(string s)
{
	for (int i = 0; i < prompt.size(); ++i)
		if (s == prompt[i])
			return i;
}

void win(string s)
{
	if (s == "player")
		cout << "\nYou win! Try again.\n";
	if (s == "computer")
		cout << "\nYou lose! Try again.\n";
}

int main()
{
	vector<int> computer;
	int player_score = 0, computer_score = 0;
	int i1 = 0, i2 = 0, i0 = 0;
	
	cout << "Type two numbers to choose where to start: ";
	cin >> i1 >> i2;
	for (int i = 0; i < 10; ++i) {
		computer.push_back(i1 % 3);
		i0 = i1;
		i1 = i2;
		i2 = i0 + i1;
	}

	cout << "The game is ready.\n"
		<< "Please type 'rock', 'scissors' or 'paper'.\n";
	for (int i = 0; i < computer.size(); ++i) {
		cout << "\nYour tern: ";
		string player = " ";
		cin >> player;
		if (get_number(player) == computer[i])
			cout << "Computer tern: " << prompt[computer[i]]
			<< "\nTry again.\n";
		else
			switch (get_number(player)) {
			case 0:
				if (computer[i] == 1) {
					cout << "Computer tern: " << prompt[computer[i]];
					win("player");
					++player_score;
				}
				else if (computer[i] == 2) {
					cout << "Computer tern: " << prompt[computer[i]];
					win("computer");
					++computer_score;
				}
				break;
			case 1:
				if (computer[i] == 2) {
					cout << "Computer tern: " << prompt[computer[i]];
					win("player");
					++player_score;
				}
				else if (computer[i] == 0) {
					cout << "Computer tern: " << prompt[computer[i]];
					win("computer");
					++computer_score;
				}
				break;
			case 2:
				if (computer[i] == 0) {
					cout << "Computer tern: " << prompt[computer[i]];
					win("player");
					++player_score;
				}
				else if (computer[i] == 1) {
					cout << "Computer tern: " << prompt[computer[i]];
					win("computer");
					++computer_score;
				}
				break;
			default:
				cout << "You treated!";
				win("computer");
				++computer_score;
			}
	}
	cout << "\nFinally, your score == " << player_score << ", computer score == " << computer_score << ".\n";
	if (player_score < computer_score)
		cout << "You lose!\n";
	else if (player_score > computer_score)
		cout << "You win!\n";
	else
		cout << "Your score is the same as the computer's!\n";
	keep_window_open();
	return 0;
}