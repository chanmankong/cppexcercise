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
	
	
	for(int row = x + 1; row < n; row++)
	for(int i = 0; i < n; i++)
	{
		if(b[row][i] == '#' && col[i])
		{
			seq++;
			col[i] = false;
			isok(ro);
			seq--;
			col[i] = true;
		}

	}

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


		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				if(b[i][j] == '#')
				{
					seq++;
					col[j] = false;
					isok(i);
					seq--;
					col[j] = true;
				}
			}

		cout << cnt << endl;

		seq = 0;
		cnt = 0;
		for(int i = 0; i < n; i++)
			b[i].clear();
		for(auto it = col.begin(); it != col.end(); it++)
			*it = true;

		cin >> n >> k;

	}


	return 0;
}
