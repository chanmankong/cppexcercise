#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
	int val;
	int x;
	int y;

	Item(int _v, int _x, int _y):val(_v), x(_x), y(_y){}
	
};

bool comp(Item &a, Item &b)
{
	return a.val < b.val;
}

struct HItem
{
	int h = -1;
	int len = 1;

	HItem(int _h):h(_h){}
	HItem(){}
};

int main()
{
	int row, col;
	cin >> row >> col;

	vector<vector<HItem> > arr(row + 2, vector<HItem>(col + 2, HItem()));
	vector<Item> sarr;
	
	int h;
	for(int i = 1; i < row + 1; i ++)
		for(int j = 1; j < col + 1; j ++)
		{
			cin >> h;
			arr[i][j].h = h;
			sarr.push_back(Item(h, i, j));
		}

	sort(sarr.begin(), sarr.end(), comp);
	
	//for(auto it = sarr.begin(); it != sarr.end(); it ++)
	//	cout << it->val << " ";
	

	int maxlen = 1;
	for(auto it = sarr.begin(); it != sarr.end(); it ++)
	{
		if(arr[it->x][it->y].h < arr[it->x + 1][it->y].h)
		{
			arr[it->x + 1][it->y].len = max(arr[it->x][it->y].len + 1, arr[it->x + 1][it->y].len);
			if(maxlen < arr[it->x + 1][it->y].len )
				maxlen = arr[it->x + 1][it->y].len; 
		}


		if(arr[it->x][it->y].h < arr[it->x][it->y + 1].h)
		{
			arr[it->x][it->y + 1].len = max(arr[it->x][it->y].len + 1, arr[it->x][it->y + 1].len);
			if(maxlen < arr[it->x][it->y +1].len )
				maxlen = arr[it->x][it->y + 1].len; 
		}


		if(arr[it->x][it->y].h < arr[it->x - 1][it->y].h)
		{
			arr[it->x - 1][it->y].len = max(arr[it->x][it->y].len + 1, arr[it->x - 1][it->y].len);
			if(maxlen < arr[it->x - 1][it->y].len )
				maxlen = arr[it->x - 1][it->y].len; 
		}


		if(arr[it->x][it->y].h < arr[it->x][it->y - 1].h)
		{
			arr[it->x][it->y - 1].len = max(arr[it->x][it->y].len + 1, arr[it->x][it->y - 1].len);
			if(maxlen < arr[it->x][it->y - 1].len )
				maxlen = arr[it->x][it->y - 1].len; 
		}
	}

	cout << maxlen << endl;


	return 0;
}
