#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> stalls;

bool isok(int dist)
{
	int last;
	int cnt = 1;
	auto i = stalls.begin();
	last = *i;
	for(i++; i != stalls.end() && cnt < c; i++)
	{
		if(*i - last >= dist)
		{
			last = *i;
			cnt ++;
		}
	}

	return (cnt == c);
}

int bisearch(int low, int high)
{
	int mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(isok(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}

	return high;
}

int main()
{
	cin >> n >> c;
	int x, last, low = 99999999, high = 0;

	for(int i = 0; i < n; i++)
	{
		cin >> x;
		if(i != 0 && x - last < low)
			low = x - last;
		last = x;
		stalls.push_back(x);
	}
	sort(stalls.begin(), stalls.end());
	high = *(stalls.end() - 1) - *stalls.begin();
	cout << bisearch(low, high) << endl;

	return 0;
}
