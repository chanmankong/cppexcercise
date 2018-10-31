#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	vector<int> vec;
	for(int i = 1; i < 10; i ++)
		vec.push_back(i);
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	cout << vec.max_size() << endl;


	return 0;
}

