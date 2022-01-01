#include "../../std_lib_facilities.h"

int main()
{   //input parts
	cout << "Enter the your name:";
	string name;
	cin >> name;

	cout << "Enter the name of the person you want to write to:";
	string first_name;
	cin >> first_name;

	cout << "Enter the name of a friend of you:";
	string friend_name;
	cin >> friend_name;

	char friend_sex = 0;
	cout << "Enter 'm' if your friend is a man and 'f' if your friend is a woman:";
	cin >> friend_sex;

	cout << "Enter recipent's age:";
	int age;
	cin >> age;

	//output parts
	cout << "\nDear, " << first_name << "!\n"
		<< "    How are you doing? I'm fine. I miss you.\n"
		<< "    Have you seen " << friend_name << " lately?\n";

	if (friend_sex == 'm')
		cout << "    If you see " << friend_name << ", please ask him to call me.\n";
	if (friend_sex == 'f')
		cout << "    If you see " << friend_name << ", please ask her to call me.\n";

	if (age <= 0, age >= 110)
		simple_error("you are kidding!");
	cout << "    I heard you just had a birthday and you are " << age << " year old.\n";

	if (age < 12)
		cout << "    Next year you will be " << age + 1 << ".\n";
	if (age == 17)
		cout << "    Next year you will be able to vote.\n";
	if (age > 70)
		cout << "    I hope you are enjoying retirement.\n";

	cout << "Your sincerely,\n\n" << name << '\n';

	keep_window_open();
	return 0;
}