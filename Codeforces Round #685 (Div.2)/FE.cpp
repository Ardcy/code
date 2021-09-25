#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
int arr[N];
const int mod = 1e9+7;
int ans[N];
int fa[N];
int depth[N];
set<int>y;
vector<int>P[N];
int looplength = 0;
void dfs(int head){
	
	for(auto p:P[head]){
		if(p==fa[head])continue;
		if(depth[p]&&looplength==0){
			looplength = depth[head]+1 - depth[p];
			continue;
		}
		depth[p] = depth[head]+1;
		fa[p] = head;
		dfs(p);
	}
	
}
signed main(){
	int t;
	cin>>t;
	
	while(t--){
		y.clear();
		int n;
		cin>>n;
		looplength = 0;
		for(int i=1;i<=n;i++)P[i].clear();
		for(int i=1;i<=n;i++){
			depth[i] = 0;
			fa[i] = 0;
			int u,v;
			cin>>u>>v;
			P[u].push_back(v);
		}
		
		depth[1] = 1;
		dfs(1);
		cout<<looplength<<endl;	
	}
} 
