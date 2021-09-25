#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
#define fi first 
#define se second
const int N = 205000;
int dep[N];
vector<int> P[N];
int f[N][20];
void dfs(int u){
	for(auto p:P[u]){
		if(dep[p])continue;
		dep[p]=dep[u]+1;
		f[p][0]=u;
		dfs(p);
	}
}
int lca(int p,int q){
	if(dep[p]<dep[q])swap(p,q);
	for(int i=18;i>=0;i--){
		if(dep[f[p][i]]>=dep[q])p=f[p][i];
	}
	for(int i=18;i>=0;i--){
		if(f[p][i]!=f[q][i])p=f[p][i],q=f[q][i];
	}
	if(p!=q)return f[p][0];
	else return p;
}
bool cmp(int a,int b){
	return dep[a]<dep[b];
}
signed main(){
	int n,m;
	cin>>n>>m;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		P[u].pb(v);P[v].pb(u);
	} 
	dep[1]=1;
	dfs(1);
	for(int i=1;i<=18;i++){
		for(int j=1;j<=n;j++){
			f[j][i]=f[f[j][i-1]][i-1];
		}
	}
	while(m--){
		vector<int>c;
		int k=0;
		cin>>k;
		int u1;
		while(k--){
			cin>>u1;
			c.pb(u1);	
		}
		sort(c.begin(),c.end(),cmp);
		int l = c.size();
		int flag = 1;
		for(int i=1;i<l;i++){
			int y = lca(c[i],c[i-1]);
			//cout<<y<<endl;
			if(dep[c[i]]-dep[y]>1&&dep[c[i-1]]-dep[y]>1)flag = 0;
		}
		if(flag==0)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
} 
