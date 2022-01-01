#include "../../std_lib_facilities.h"

const int empty_room = 0;
const int player = 1;
const int wumpus = 2;
const int pit = 3;
const int bat = 4;

struct Room
{
	Room(int num, int f, int l, int r)
		:number{ num }, front{ f }, left{ l }, right{ r }, state{ empty_room } { }

    int number;
    int front;
    int left;
    int right;
    int state;
};

ostream& operator<<(ostream& os, const Room& r)
{
	return os << "You are in room " << r.number << "; there are tunnels to room " 
		<< r.front << ", " << r.left << " and " << r.right << ";\n";
}

vector<Room> rooms{ { 0, 0, 0, 0 }, { 1, 16, 4, 2 }, { 2, 7, 1, 3 }, { 3, 14, 2, 4 }, { 4, 5, 3, 1 }, 
{ 5, 4, 6, 8 }, { 6, 11, 7, 5 }, { 7, 2, 8, 6 }, { 8, 9, 5, 7 }, { 9, 8, 12, 10 }, { 10, 15, 9, 11 }, 
{ 11, 6, 10, 12 }, { 12, 13, 11, 9 }, { 13, 12, 14, 16 }, { 14, 3, 15, 13 }, { 15, 10, 16, 14 }, { 16, 1, 13, 15 } };

int player_room = 0;
int player_arrow = 5;
bool game_over = false;
bool win = false;

void help_doc()
{
	cout << "Welcome to the game \"Hunt the Wumpus\"\n"
		<< "A rather smelly monster lives in a dark cave consisting of connected rooms. "
		<< "Your job is to slay the wumpus using bow and arrow. "
		<< "In addition to the wumpus, the cave has two hazards: bottomless pits and giant bats. "
		<< "If you enter a room with a bottomless pit, it's the end of the game for you. "
		<< "If you enter a room with a bat, the bat picks you up and drops you into another room. "
		<< "If you enter the room with the wumpus or he enters yours, he eats you. "
		<< "When you enter a room you will be told if a hazard is nearby:\n"
		<< "\t\"I smell the wumpus\": It's in an adjoining room.\n"
		<< "\t\"I feel a breeze\": One of the adjoining rooms is a bottomless pit.\n"
		<< "\t\"I hear a bat\": A giant bat is in an adjoining room.\n"
		<< "When entering a room, you are told something like \"You are in room 12; "
		<< "there are tunnels to rooms 1, 13, and 4; move or shoot?\" "
		<< "Possible answers are m13(\"Move to room 13\") and s13-4-3(\"Shoot an arrow through rooms 13, 4, and 3\"). "
		<< "The range of an arrow is three rooms. At the start of the game, you have five arrows. "
		<< "The snag about shooting is that it wakes up the wumpus and he moves to a room adjoining the one he was in - "
		<< "that could be your room.\n\n";
}

void initialize()
{
    player_room = randint(1, 16);
	rooms[player_room].state = player;

	while (true) {
		int i = randint(1, 16);
		if (rooms[i].state == empty_room) {
			rooms[i].state = wumpus;
			break;
		}
	}

	while (true) {
		int i = randint(1, 16);
		if (rooms[i].state == empty_room) {
			rooms[i].state = pit;
			break;
		}
	}

	while (true) {
		int i = randint(1, 16);
		if (rooms[i].state == empty_room) {
			rooms[i].state = bat;
			break;
		}
	}
}

void detect()
{
	Room r = rooms[player_room];
	cout << r;

	if (rooms[r.front].state == wumpus || rooms[r.left].state == wumpus || rooms[r.right].state == wumpus)
		cout << "I smell the wumpus.\n";
	if (rooms[r.front].state == pit || rooms[r.left].state == pit || rooms[r.right].state == pit)
		cout << "I feel a breeze.\n";
	if (rooms[r.front].state == bat || rooms[r.left].state == bat || rooms[r.right].state == bat)
		cout << "I hear a bat.\n";

	cout << "move or shoot?\n";
}

void analyze()
{
	if (player_arrow == 0) {
		game_over = true;
		cout << "You are out of arrow! ";
		return;
	}

	Room r = rooms[player_room];

	string s;
	cin >> s;
	istringstream iss{ s };

	char ch;
	iss >> ch;
	switch (ch) {
	case 'm':
	{
		int dest = 0;
		iss >> dest;

		if (r.front != dest && r.left != dest && r.right != dest)
			error("no tunnel to room ", dest);

		switch (rooms[dest].state) {
		case wumpus:
				game_over = true;
				cout << "Oh! You have been enten by Wumpus. ";
				return;
		case pit:
				game_over = true;
				cout << "Oh! You entered the endless pit. ";
				return;
		case bat:
				cout << "Oh! You are caught by the bat.\n";
				while (true) {
					int i = randint(1, 16);
					if (rooms[i].state == empty_room) {
						rooms[i].state = player_room;
						return;
					}
				}
		}

		rooms[player_room].state = empty_room;
		player_room = dest;
		return;
	}
	case 's':
	{
		int r1 = 0, r2 = 0, r3 = 0;
		char ch1, ch2;
		iss >> r1 >> ch1 >> r2 >> ch2 >> r3;

		if (iss && (ch1 != '-' || ch2 != '-'))
			error("bad input format");

		--player_arrow;
		if (r.front != r1 && r.left != r1 && r.right != r1)
			error("bad input: no tunnel to room ", r1);
		if (rooms[r1].front != r2 && rooms[r1].left != r2 && rooms[r1].right != r2)
			error("bad input: no tunnel to room ", r2);
		if (rooms[r2].front != r3 && rooms[r2].left != r3 && rooms[r2].right != r3)
			error("bad input: no tunnel to room ", r3);

		if (rooms[r1].state == wumpus || rooms[r2].state == wumpus || rooms[r3].state == wumpus) {
			win = true;
			cout << "You win the game!\n";
			return;
		}
		else {
			int wumpus_room = 0;
			for (int i = 1; i <= 16; ++i)
				if (rooms[i].state == wumpus) {
					wumpus_room = i;
					break;
				}
			if (rooms[rooms[wumpus_room].front].state == empty_room) {
				rooms[wumpus_room].state = empty_room;
				rooms[rooms[wumpus_room].front].state = wumpus;
			}
			else if (rooms[rooms[wumpus_room].left].state == empty_room) {
				rooms[wumpus_room].state = empty_room;
				rooms[rooms[wumpus_room].left].state = wumpus;
			}
			else if (rooms[rooms[wumpus_room].right].state == empty_room) {
				rooms[wumpus_room].state = empty_room;
				rooms[rooms[wumpus_room].right].state = wumpus;
			}
			return;
		}
	}
	default:
		error("bad input format");
		return;
	}
}

void play()
{
	help_doc();

    while (!game_over)
	try {
		detect();
		analyze();
		if (win)
			return;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
	}

	cout << "Game is over! Good game!\n";
	return;
}

int main()
{
    initialize();
    play();
	keep_window_open();
}