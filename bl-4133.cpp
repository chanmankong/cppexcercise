#include <iostream>
#include <vector>
using namespace std;

void check(int &left, int &right, int &top, int &bottom, int x, int y)
{
	if(x < left)
		left = x;
	if(x > right)
		right = x;
	if(y < top)
		top = y;
	if(y > bottom)
		bottom = y;

	return;
}

int garbage(vector<vector<int> > &board, int x, int y, int d)
{
	int total = 0;
	int left = max(0, x - d);
	int right = min(1024, x + d);
	int top = max(0, y - d);
	int bottom = min(1024, y + d);

	for(int i = left; i <= right; i++)
		for(int j = top; j <= bottom; j++)
			total += board[i][j];

	return total;
}

int main()
{
	int d, n;
	cin >> d >> n;

	vector<vector<int> > block(1025, vector<int>(1025, 0));
	int left = 1024, right = 0, top = 1024, bottom = 0;
	for(int i = 0; i< n; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		block[x][y] = t;
		check(left, right, top, bottom, x, y);
	}

	int cnt = 0, max_garbage = 0;
	int t = 0;
	for(int i = left; i <= right; i++)
		for(int j = top; j <= bottom; j++)
		{
			t = garbage(block, i, j, d);
			if(t > max_garbage)
			{
				max_garbage = t;
				cnt = 1;
			}
			else if(t == max_garbage)
				cnt++;
			else
				continue;
		}

	cout << cnt << " " << max_garbage << endl;

	return 0;
}
