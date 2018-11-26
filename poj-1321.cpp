#include <iostream>
#include <vector>
using namespace std;

const int Max_size = 8;
vector<vector<char> > b(Max_size);
vector<bool> col(Max_size, true);
int cnt = 0;
int seq = 0;
int n, k;

void isok(int x)
{

	if(seq == k)
	{
		cnt ++;
		return;
	}

	if(x >= n)
		return;
	
	// if I put a chess in the current row, I should try every column in this row
	for(int i = 0; i < n; i++)
	{
		if(b[x][i] == '#' && col[i])
		{
			seq++;
			col[i] = false;
			isok(x + 1);
			seq--;
			col[i] = true;
		}

	}

	// if I don't put a chess in the current row, then I try the next row
	isok(x + 1);

	return;
}

int main()
{
	char c;
	
	cin >> n >> k;
	while(n != -1 && k != -1)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				cin >> c;
				b[i].push_back(c);
			}

		isok(0);
		cout << cnt << endl;

		cnt = 0;
		for(int i = 0; i < n; i++)
			b[i].clear();
		for(auto it = col.begin(); it != col.end(); it++)
			*it = true;

		cin >> n >> k;

	}


	return 0;
}
