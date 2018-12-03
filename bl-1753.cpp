#include <iostream>
#include <bitset>
#include <string>
#include <deque>
using namespace std;

const unsigned int MX = 1 << 16;
bitset<MX> flags;
struct Node
{
	unsigned state;
	int round;

	Node(unsigned s, int n): state(s), round(n){}
};

deque<Node> que;
const unsigned int goal0 = 0;
const unsigned int goal1 = (1 << 16) - 1;

unsigned int bit2int(bitset<16> b)
{
	return b.to_ulong();
}

bitset<16> int2bit(unsigned int a)
{
	return bitset<16>(a);
}

void newround(bitset<16> board, int n, int round)
{
	board.flip(n);
	if(n - 4 >= 0)
		board.flip(n - 4);
	if(n % 4 != 0)
		board.flip(n - 1);
	if(n % 4 != 3)
		board.flip(n + 1);
	if(n + 4 <= 15)
		board.flip(n + 4);
	unsigned int state = bit2int(board);
	if(flags[state])
		return;
	que.push_back(Node(state, ++round));
	flags.set(state);

	return;
}

int BFS(unsigned int start)
{
	que.push_back(Node(start, 0));
	flags.set(start);
	Node now(-1, 0);
	bitset<16> board;

	while(!que.empty())
	{
		now = que.front();
		que.pop_front();
		if(now.state == goal1 || now.state == goal0)
			return now.round;

		board = int2bit(now.state);
		for(int i = 0; i < 16; i++)
			newround(board, i, now.round);
	}

	return -1;
}


int main()
{
	string b;
	char c;
	for(int i = 0; i < 16; i++)
	{
		cin >> c;
		if(c == 'b')
			b += '0';
		else
			b += '1';
	}

	bitset<16> bb(b);
	int start = bit2int(bb);
	int  r = BFS(start);
	if(r == -1)
		cout << "Impossible" << endl;
	else
		cout << r << endl;

	return 0;
}
