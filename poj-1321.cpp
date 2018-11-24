#include <iostream>
#include <vector>
using namespace std;

class Item
{
	public:
		int x, y;
		bool flag;

		Item(int xx, int yy, bool ff):x(xx), y(yy), flag(ff){}
};

void isok(vector<vector<char> > &c, int x, int y, int seq, int k, int &cnt)
{
	int next_x = x + 1, next_y1 = y - 1, next_y2 = y + 1;

	if(seq == k)
	{
		cnt ++;
		cout << "ok: " << x << " " << y << endl; 
		return;
	}

	if(next_x < c.size() && next_y1 > -1 && c[next_x][next_y1] == '#')
		isok(c, next_x, next_y1, seq + 1, k, cnt);
	
	if(next_x < c.size() && next_y2 < c.size() && c[next_x][next_y2] == '#')
		isok(c, next_x, next_y2, seq + 1, k, cnt);

	return;
}

int main()
{

	int n, k;
	char c;
	
	cin >> n >> k;
	while(n != -1 && k != -1)
	{
		vector<vector<char> > b(n);
		vector<Item> li;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				cin >> c;
				b[i].push_back(c);
				if(c == '#')
					li.push_back(Item(i, j, false));
			}

		int cnt = 0;

		for(auto it = li.begin(); it != li.end(); it++)
			isok(b, (*it).x, (*it).y, 1, k, cnt);

		cout << cnt << endl;

		cin >> n >> k;

	}


	return 0;
}
