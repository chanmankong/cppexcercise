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

	vector<vector<int> > v(n + 1, vector<int>(m + 1, 0));
	vector<Item> arr(1, Item(0, 0));

	int _w, _v;
	for(int i = 0; i < n; i ++)
	{
		cin >> _w >> _v;
		arr.push_back(Item(_w, _v));
	}

	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			if(j >= arr[i].w)
				v[i][j] = max(v[i - 1][j], v[i - 1][j - arr[i].w] + arr[i].v);
			else
				v[i][j] = v[i - 1][j];
		}

	cout << v[n][m] << endl;

	return 0;
}
