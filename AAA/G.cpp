#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e10;
const int N = 20005;
const int B = 150;
int n,q;
int deg[N],dep[N];
int a[N],fa[N],fe[N];
vector<int>g[N];
inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void predfs(int u){
	dep[u]=dep[fa[u]]+1;
	for(int v:g[u]){
		if(v==fa[u])continue;
		fa[v]=u,fe[v]=(deg[u]>B||deg[v]>B?inf:gcd(a[u],a[v]));
		predfs(v);
	}
}
signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		++deg[u],++deg[v];
		g[u].push_back(v),++deg[u];g[v].push_back(u),++deg[v];
	}
	predfs(1);
	for(int i=1,opt,u,v,x;i<=q;i++){
		cin>>opt>>u>>v;
		if(opt==1){
			a[u]=v;
			if(deg[u]>B)continue;
			for(int v:g[u]){
				if(deg[v]>B)continue;
				if(fa[u]==v){
					fe[u]=gcd(a[u],a[v]);
				}else{
					fe[v]=gcd(a[u],a[v]);
				}
			}
		}else{
			cin>>x;
			int ans = 0;
			if(dep[u]<dep[v])swap(u,v);
			while(dep[u]>dep[v]){
				ans+=(fe[u]<=x);
				if(deg[u]>B||deg[fa[u]]>B){
					ans+=(gcd(a[u],a[fa[u]])<=x);
				}
				u=fa[u];
			}
			if(u==v)goto print;
			while(u!=v){
				ans+=(fe[u]<=x);
				if(deg[u]>B||deg[fa[u]]>B)
					ans+=(gcd(a[u],a[fa[u]]<=x));
				u=fa[u];
				ans+=(fe[v]<=x);
				if(deg[v]>B||deg[fa[v]]>B)
					ans+=(gcd(a[v],a[fa[v]])<=x);
				v=fa[v];
			}
			print:
			cout<<ans<<endl;
		}
	}
	return 0;
}
