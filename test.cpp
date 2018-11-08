#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> a(10);

	for(int i = 0; i < 10; i ++)
	{
		int  h;
		cin >> h;
		a.push_back(h);
	}

	auto r = find(a.begin(), a.end(), 88);

	cout << *r << endl;


	return 0;
}
