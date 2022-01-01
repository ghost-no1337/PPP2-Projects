#include "../../std_lib_facilities.h"

int ga[10]{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(int arr[], int no)
{
    int la[10];
	for (int i = 0; i < 10; ++i)
		la[i] = ga[i];
	for (int i = 0; i < 10; ++i)
		cout << la[i] << '\n';
    
    int* p = new int[no];
	for (int i = 0; i < no; ++i)
		p[i] = arr[i];
	for (int i = 0; i < no; ++i)
		cout << p[i] << '\n';
    
    delete[] p;
}

int main()
{
    f(ga, 10);
	int aa[10]{ 1, 2 * 1, 3 * 2 * 1, 4 * 3 * 2 * 1, 5 * 4 * 3 * 2 * 1, 6 * 5 * 4 * 3 * 2 * 1, 
		7 * 6 * 5 * 4 * 3 * 2 * 1, 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1, 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1, 
		10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 };
    f(aa, 10);

    keep_window_open();
}