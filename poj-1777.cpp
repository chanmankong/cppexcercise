#include <iostream>
#include <string>
using namespace std;

void bubble(string vec[], int n)
{
	for(int i = 0; i < n - 1; i ++)
		for(int j = 0; j < n - 1 - i; j ++)
		{
			if(vec[j] > vec[j + 1])
			{
				string temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
			}
		}
	return;
}

void lsdir(string dir, int depth, int no)
{
	string vec[30];
	int n = 0;
	string f, prefix = "";

	for(int i = 0; i < depth; i ++)
		prefix +="|     ";

	cin >> f;
	if(f == "#")
		exit(0);
	else if(no != -1)
		cout << "DATA SET " << no << ":" << endl;

	cout << prefix << dir << endl;
	while(f != "]" && f != "*")
	{
		if(f[0] == 'd')
			lsdir(f, depth + 1, -1);
		else if(f[0] == 'f')
			vec[n ++] = f;
		else
			break;
		cin >> f;
	}

	bubble(vec, n);
	for(int i = 0; i < n; i ++)
		cout << prefix << vec[i] << endl;

	return;
}

int main()
{
	string f = "ROOT";
	int n = 1;
	
	while(true)
	{
		lsdir(f, 0, n++);
		cout << endl;
	}

	return 0;
}


