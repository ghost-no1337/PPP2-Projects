#include "../../std_lib_facilities.h"

int main()
{
	vector<double> distances;
	for (double distance; cin >> distance; )
		distances.push_back(distance);
	sort(distances);
	cout << "The smallest of the distances is " << distances[0] << ".\n"
		<< "The largest of the distances is " << distances[distances.size() - 1] << ".\n";

	if (distances.size() % 2 == 1)
		cout << "The mean distance is " << (distances[distances.size() / 2] + distances[distances.size() / 2 + 1]) / 2 << ".\n";
	else
		cout << "The mean distance is " << distances[distances.size() / 2 + 1] << ".\n";

	keep_window_open();
	return 0;
}