#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


list<int> radix_list(list<int> l, int t) {
	int i, j, d, m = 1;
	list<int> temp[10];

	for (j = 1; j <= t; j++) {
		for (int el : l) {
			d = ((int)(el / m) % 10);
			temp[d].push_back(el);
		}
		l.clear();
		for (i = 0; i <= 9; i++) {
			l.insert(l.end(), temp[i].begin(), temp[i].end());
			temp[i].clear();
		}
		m *= 10;
	}
	return l;
}
int main()
{
	list<int> inp{ 523,153,88,554,235,4 }, out;
	int maxEl = *inp.begin();
	for (int el : inp)
		maxEl = max(maxEl, el);
	int t = 0;
	while (maxEl > 0)
	{
		maxEl /= 10;
		t++;
	}
	out = radix_list(inp, t);
	return 0;


}
