#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
vector<int>P[205000];
int dep[205000];
int son[205000];
void dfs(int a,int b){
	dep[a]=dep[b]+1;
	for(auto p:P[a]){
		if(p==b)continue;
		else{
			dfs(p,a);
			son[a]+=son[p]+1;
		}
	}
}
struct node{
	int x,y;
	bool operator<(node &t)const{
		return x-y>t.x-t.y;
	}
}e[205000];
signed main(){
	int n,k;
	cin>>n>>k;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		P[u].pb(v);P[v].pb(u);
	}
	int sum = 0;dep[0]=-1;
	dfs(1,0);
	
	for(int i=1;i<=n;i++){
		e[i].x=dep[i];
		e[i].y=son[i];
	}
	sort(e+1,e+n+1);
	for(int i=1;i<=k;i++){
		
		sum+=e[i].x-e[i].y;
	}
	cout<<sum<<endl;
	return 0;
}


