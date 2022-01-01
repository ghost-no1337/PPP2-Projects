#include "../../std_lib_facilities.h"
#include <chrono>
using namespace std::chrono;

void make_test_specified(int num, vector <double>& v)
{
	for (int i = 0; i < num; ++i)
		v[i] = randint(0, 100);
}

void test_time(vector<double>& v)
{
	auto start = system_clock::now();
	sort(v);
	auto end = system_clock::now();
	cout << "sort a vector of " << v.size() << " took "
		<< duration_cast<milliseconds>(end - start).count() << " milliseconds\n";
}

int main()
{
    vector<double> test1(500000);
    make_test_specified(500000, test1);
    vector<double> test2(5000000);
    make_test_specified(5000000, test2);
    
    test_time(test1);
    test_time(test2);
    
    keep_window_open();
}