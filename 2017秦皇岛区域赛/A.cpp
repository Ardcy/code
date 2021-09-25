#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <sstream>
#define int long long
using namespace std;

const int MAXN = 100 + 10;

int n;

map<string, int> mp;

int vis[MAXN];

vector<int> E[MAXN]; 

int inEdge[MAXN], temp[MAXN];

int hasCycle;

string ans1, ans2;

signed main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	while(cin >> n)
	{
		for(int i = 0; i <= 2 * n; i++)
		{
			E[i].clear();
		}
		memset(inEdge, 0, sizeof(inEdge));
		mp.clear();
		hasCycle = 0;
		int idx = 0;
		for(int i = 0; i < n; i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			if(!mp.count(s1)) mp[s1] = idx++;
			if(!mp.count(s2)) mp[s2] = idx++;
			if (mp[s1] > mp[s2] && hasCycle != 1) {
				hasCycle = 1;
				ans1 = s1, ans2 = s2;
			}
//			int u = mp[s1], v = mp[s2];
//			E[u].push_back(v);
//			inEdge[v]++;
//			if(hasCycle == 0)
//			{
//				memcpy(temp, inEdge, sizeof(inEdge));
//				queue<int> que;
//				for(int j = 0; j < idx; j++)
//				{
//					if(!temp[j]) que.push(j);
//				}
//				int cnt = 0;
//				while(!que.empty())
//				{
//					int u = que.front();
//					que.pop();
//					cnt++;
//					for(auto v : E[u])
//					{
//						temp[v]--;
//						if(!temp[v]) que.push(v);
//					}
//				}
//				if(cnt != idx)
//				{
//					hasCycle = 1;
//					ans1 = s1, ans2 = s2;
//				}
//			}
		}
		if(hasCycle)
		{
			cout << ans1 << " " << ans2 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
