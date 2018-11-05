#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void len(int i, int j, auto &vec, string &s1, string &s2)
{
	if(s1[i - 1] == s2[j - 1])
		vec[i][j] = vec[i - 1][j - 1] + 1;
	else
		vec[i][j] = max(vec[i][j - 1], vec[i - 1][j]); 
}
int main()
{
	string s1, s2;
	while(cin >> s1 && cin >> s2)
	{
		vector<vector<int> > vec(s1.size() + 1, vector<int>(s2.size() + 1, 0) );
		for(int i = 1; i <= s1.size(); i ++)
			for(int j = 1; j <= s2.size(); j ++)
				len(i, j, vec, s1, s2);

		cout << vec[s1.size()][s2.size()] << endl;
	}

	return 0;
}
