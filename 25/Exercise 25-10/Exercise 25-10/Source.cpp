#include "../../std_lib_facilities.h"

struct PPN {
    unsigned int PFN : 22 ;
    int : 3 ;
    unsigned int CCA : 3 ;
    bool nonreachable : 1 ;
    bool dirty : 1 ;
    bool valid : 1 ;
    bool global : 1 ;
};

int main()
{
	unsigned int i = 0;
	cin >> i;
	PPN pn = { i };
	cout << pn.PFN << ' ' << pn.CCA << '\n';
	keep_window_open();
}