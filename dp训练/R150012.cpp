#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
vector<pair<int,int> >P[300];
set<int>Pr;
int ans = 0;
int vis[200];
void dfs(int u,int v,int from,int ui){

	if(u==v){
		ans=1;return;
	}
	if(vis[u])return;
	vis[u]=1;
	for(auto p:P[u]){
		if(p.fi==from)continue;
		if(p.se==ui){
			dfs(p.fi,v,u,ui);
		}
	}
}
signed main(){
	int n,m;
	cin>>n>>m;
	int u,v,id;

	for(int i=1;i<=m;i++){
		cin>>u>>v>>id;
		if(Pr.find(id)==Pr.end())Pr.insert(id);
		P[u].pb(mp(v,id));P[v].pb(mp(u,id));
	}
	int t;
	cin>>t;
	while(t--){
		
		int a,b;
		cin>>a>>b;
		int cnt = 0;
		for(auto p:Pr){
			ans = 0;memset(vis,0,sizeof(vis));
			dfs(a,b,-1,p);
			cnt+=ans;
		}
		cout<<cnt<<endl;
	}
	return 0;
	
	
	
}

/*
100 100
2 8 5 1 10 5 5 6 6 2 8 2 2 6 3 7 9 6 9 10 3 8 10 6 3 4 4 4 9 8 
8 10 4 2 10 9 3 9 7 1 3 5 1 10 1 1 7 2 4 9 10 4 5 5 5 10 7 4 8 9 
2 4 6 1 8 7 4 7 2 1 10 8 4 8 3 2 5 7 1 8 2 6 10 10 3 7 7 1 4 9 
1 2 3 5 8 9 4 6 2 2 5 4 1 9 8 8 9 4 4 5 10 1 10 10 7 9 4 5 9 5 
1 9 9 1 7 9 3 9 3 9 10 1 8 9 2 6 9 7 2 3 5 3 6 9 3 5 7 2 9 3 
2 10 6 7 8 8 7 10 9 3 6 6 5 10 2 3 6 1 4 10 7 8 10 10 4 6 8 3 10 2 
3 10 4 6 10 7 4 5 3 6 9 2 3 6 8 4 9 3 4 5 4 1 7 8 5 6 5 5 9 3 
2 7 9 1 7 1 7 8 4 3 7 6 6 8 10 7 8 2 1 3 7 5 9 4 9 10 4 1 8 5 
1 9 4 5 6 1 2 5 6 4 6 7 2 10 2 3 8 7 3 8 10 3 4 8 8 9 6 6 10 6 
5 6 4 1 9 10 2 4 5 4 7 6 3 9 2 1 4 2 4 7 4 1 4 6 3 9 1 6 10 2 
100
41 89 6 91 8 90 1 46 4 15 2 41 5 59 6 60 3 6 5 82 4 10 6 9 3 8 10 7 2 8 
8 2 10 1 4 5 2 8 6 4 14 3 5 2 3 10 1 9 8 5 6 7 9 1 5 4 2 4 7 4 
11 2 10 1 5 3 10 4 2 5 9 3 1 6 6 10 4 3 9 8 85 9 2 5 4 6 6 3 7 9 
10 3 10 6 10 5 6 1 6 9 19 1 2 4 3 8 1 4 2 4 4 8 1 10 9 4 8 9 4 8 
10 4 10 2 9 3 9 1 2 9 5 9 7 1 10 4 9 8 7 4 36 7 6 9 4 10 5 9 4 10 
8 7 5 6 9 7 2 6 6 2 50 7 5 6 5 3 6 4 3 7 9 3 4 10 5 6 7 3 6 4 
66 7 7 2 7 3 7 9 3 6 6 2 1 2 6 2 8 7 3 5 
*/
