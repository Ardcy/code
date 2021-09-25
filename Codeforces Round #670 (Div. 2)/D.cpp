#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
using namespace std;
int N;
const int maxn = 200000;
vector<int> tree[maxn + 5];
int d[maxn + 5];
#define INF 10000000
int minNode;
int minBalance;
int y = 1;
int ans;
void dfs1(int node, int parent) {
	d[node] = 1;
	int maxSubTree = 0;

	for(auto p:tree[node]) {
		if(p==parent)continue;
		dfs1(p,node);
		d[node]+=d[p];
		maxSubTree = max(maxSubTree,d[p]);
	}
	maxSubTree = max(maxSubTree, N - d[node]);
	if (maxSubTree == minBalance) {
		minBalance = maxSubTree;
		ans = minNode;
		minNode = node;
		y = 0;
	}
	if (maxSubTree < minBalance) {
		minBalance = maxSubTree;
		minNode = node;
		y=1;
	}

}

int main() {
	int t;
	cin>>t;
	while (t--) {
		y=1;
		cin>>N;
		for (int i = 1; i <= N - 1; i++) {
			tree[i].clear();
			d[i]=0;
		}
		for (int i = 1; i <= N-1; i++) {
			int u, v;
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		minNode = 0;
		minBalance = INF;
		dfs1(1, 0);
		int minnode=minNode;
		//	cout<<y<<endl;
		if(y) {
			cout<<minnode<<" "<<tree[minnode][0]<<endl;
			cout<<minnode<<" "<<tree[minnode][0]<<endl;
		} else {
			//cout<<ans<<" "<<minnode<<endl;

			if(tree[minnode][0]==ans) {
				cout<<minnode<<" "<<tree[minnode][1]<<endl;
				cout<<ans<<" "<<tree[minnode][1]<<endl;
			} else {
				cout<<minnode<<" "<<tree[minnode][0]<<endl;
				cout<<ans<<" "<<tree[minnode][0]<<endl;
			}
		}

	}
	return 0;
}
