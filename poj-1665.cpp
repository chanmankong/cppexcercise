#include <iostream>
using namespace std;

long long count[31] = {0};

long long total(int n)
{
	if(count[n] != 0)
		return count[n];

	long long sum = 0;
	for(int i = 0; i < n - 2; i += 2)
	{
		sum += 2 * total(i);
	}

	sum += 3 * total(n - 2);
	if(count[n] == 0)
		count[n] = sum;

	return sum;
}

int main()
{
	count[0] = 1;
	count[2] = 3;
	int n;
	while(cin >> n && n != -1)
	{
		if(count[n] != 0)
			cout << count[n] << endl;
		else
			cout << total(n) << endl;

	}

	return 0;
}
