#include<bits/stdc++.h>
using namespace std;
int n,a[200000],dp[200000];
vector<int>adj[mxN];
void dfs1(int u=0,int p=-1){
	dp[u]=a[u];
	for(int v:adj[u]){
		if(v==p)continue;
		dfs1(v,u);
		dp[u]+=max(dp[v],0);
	}
}
void dfs2(int u=0,int p=-1){
	if(p!=-1)dp[u]=dp[u]+max(dp[p]-max(dp[u],0),0);
	for(int v:adj[u]){
		if(v==p)continue;
		dfs2(v,u);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(!a[i])a[i]=-1;
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v,--u,--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1();
	dfs2();
	for(int i=0;i<n;i++){
		cout<<dp[i]<<" ";
	}
}
