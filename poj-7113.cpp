#include <iostream>
#include <vector>
using namespace std;

struct Item
{
	int w;
	int v;

	Item(int _w, int _v): w(_w), v(_v){}
};

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> v(m + 1, 0);
	vector<Item> arr(1, Item(0, 0));

	int _w, _v;
	for(int i = 0; i < n; i ++)
	{
		cin >> _w >> _v;
		arr.push_back(Item(_w, _v));
	}

	for(int i = 1; i <= n; i ++)
		for(int j = m; j >= arr[i].w; j --)
			v[j] = max(v[j], v[j - arr[i].w] + arr[i].v);

	cout << v[m] << endl;

	return 0;
}
