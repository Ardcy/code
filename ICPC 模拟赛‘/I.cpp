#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 50 + 10;

char g[MAXN][MAXN];

int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Node
{
	string str;
	vector<pair<int, int>> vec;
} nodes[MAXN];

void add(int cur, int x, int y)
{
	nodes[cur].str += g[x][y];
	nodes[cur].vec.push_back(make_pair(x, y));	
}

signed main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
	}
	for(int loop = 0; loop < n / 2; loop++)
	{
		int sx = loop, sy = loop;
		for(int way = 0; way < 4; way++)
		{
			for(int i = 0; i < n - 2 * loop - 1; i++)
			{
				int newx = sx + direct[way][0], newy = sy + direct[way][1];
				add(loop, sx, sy);
				sx = newx, sy = newy;
			}
		}
//		cout << nodes[loop].str << endl;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		char op;
		cin >> op;
		if(op == 'L' || op == 'R')
		{
			int idx, num;
			cin >> idx >> num;
			idx--;
			num %= 4;
			if(op == 'R')
			{
				num = 4 - num;
			}
			string temp = "";
			int len = nodes[idx].str.length();
			for(int j = 0; j < len; j++)
			{
				temp += nodes[idx].str[(num * (len / 4) + j) % len];
			}
			nodes[idx].str = temp;
			int now = 0;
			for(auto p : nodes[idx].vec)
			{
				int x = p.first, y = p.second;
				g[x][y] = temp[now++];
			}
		}
		else
		{
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < n; k++)
				{
					cout << g[j][k];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
