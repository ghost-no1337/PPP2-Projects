#include "../../std_lib_facilities.h"

struct File_handle : std::fstream
{
	File_handle(const string& s);
	~File_handle();
};

File_handle::File_handle(const string& s)
{
	open(s);
}

File_handle::~File_handle()
{
	close();
}

int main()
{
	cout << "Please enter the file name: ";
	string fname;
	cin >> fname;
	File_handle file{ fname };

	char ch;
	while (file.get(ch))
		cout << ch;

	cout << '\n';
	keep_window_open();
}