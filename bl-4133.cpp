#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int x, y;
	int garbage;
	Node(int _x, int _y, int _g):x(_x), y(_y), garbage(_g){}
};

int main()
{
	int d, n;
	cin >> d >> n;

	vector<Node> vec;
	for(int i = 0; i< n; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		vec.push_back(Node(x, y, t));
	}

	int cnt = 0, max_garbage = 0;
	for(int i = 0; i < 1025; i++)
		for(int j = 0; j < 1025; j++)
		{
			int sum = 0;
			for(auto iter = vec.begin(); iter != vec.end(); iter++)
			{
				if(iter->x >= i - d && iter->x <= i + d && iter->y >= j - d && iter->y <= j + d)
					sum += iter->garbage;

			}

			if(sum > max_garbage)
			{
				max_garbage = sum;
				cnt = 1;
			}
			else if(sum == max_garbage)
				cnt++;
		}

	cout << cnt << " " << max_garbage << endl;

	return 0;
}
