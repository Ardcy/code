#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>P[1000];
int d[1000];
void dfs(int p){
	for(auto p1:P[p]){
		if(d[p1]==0)d[p1]=1,dfs(p1);
	}
}
signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		P[u].pb(v);
		P[v].pb(u);
	}
	int cnt = 0;
	for(int i=1,w;i<=k;i++){
		cnt=0;
		for(int i=1;i<=n;i++)d[i]=0;
		scanf("%d",&w);
		d[w]=1;
		for(int p=1;p<=n;p++){
			if(d[p]==0)d[p]=1,cnt++,dfs(p);
		}
		cout<<cnt-1<<endl;
	}
}
