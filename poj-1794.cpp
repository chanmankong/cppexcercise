#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i ++)
	{
		int s, a, b;
		cin >> s;

		cin >> a;
		int temp;
		vector<int> veca;
		for(int j = 0; j < a; j ++)
			if(cin >> temp && temp <= s)
				veca.push_back(temp);
		cin >> b;
		vector<int> vecb;
		for(int j = 0; j < b; j ++)
			if(cin >> temp && temp <= s)
				vecb.push_back(temp);

		//int max = maxa > maxb ? maxa : maxb;
		//vector<vector<bool> > p(max + 1, vector<bool>(max + 1, false));
		int r = 0;

		for(auto ita = veca.begin(); ita != veca.end(); ita ++)
			for(auto itb = vecb.begin(); itb != vecb.end(); itb ++)
			{
				if(*ita + *itb == s)
				{
					r ++;
				}
			}
		cout << r << endl;

	}

	return 0;
}
