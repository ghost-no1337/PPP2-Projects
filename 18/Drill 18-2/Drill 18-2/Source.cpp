#include "../../std_lib_facilities.h"

vector<int> gv = { 1, 2, 4, 8, 16, 32, 64, 28, 256, 512 };

void f(vector<int> vec)
{
    vector<int> lv(gv.size());
	lv = gv;
	for (int i : gv)
		cout << i << '\n';
    
    vector<int> lv2 = vec;
	for (int i : lv2)
		cout << i << '\n';
}

int main()
{
    f(gv);
	vector<int> vv = { 1, 2 * 1, 3 * 2 * 1, 4 * 3 * 2 * 1, 5 * 4 * 3 * 2 * 1, 6 * 5 * 4 * 3 * 2 * 1, 
		7 * 6 * 5 * 4 * 3 * 2 * 1, 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1, 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1, 
		10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 };
    f(vv);

	keep_window_open();
}