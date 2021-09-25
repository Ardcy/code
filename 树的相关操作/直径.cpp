#include<iostream>
#include<cstring>
#include<vector>
#define rep(i,l,r) for(int i=l;i<r;i++)
#define Rep(i,l,r) for(int i=l;i<=r;i++)
#define rrep(i,l,r) for(int i=r;i>=l;i--)
#define lc rt<<1
#define lson l,m,rt<<1
#define rc rt<<1|1
#define rson m+1,r,rt<<1|1
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+10;
vector<pii>G[N];
int d,n,s,maxDep,lp,rp,ans;
bool vis[N];
int dep[N];
void dfs(int u){
	vis[u]=true;
	if(dep[u]>maxDep){
		maxDep = dep[u];
		lp=u;
	}
	int sz=G[u].size();
	int v;
	rep(i,0,sz){
		v=G[u][i].second;
		if(!vis[v]){
			dep[v]=dep[i]+G[u][i].first;
			dfs(v);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>s){
		int x,y,v;
		ans = 0;
		Rep(i,1,n)G[i].clear();
		rep(i,0,n-1){
			cin>>x>>y>>v;
			ans+=v;
			G[x].pb(mp(v,y));
			G[y].pb(mp(v,x));
		}
		ans*=2;
		memset(vis,false,sizeof vis);
		maxDep=-1,lp=-1;
		dep[1]=0;
		dfs(1);
		memset(vis,false,sizeof vis);
		int tp=lp;
		maxDep=-1,lp=-1;
		dep[tp]=0;
		dfs(tp);
		ans-=dep[lp];
		cout<<ans<<endl;
	}
	return 0;
}


 
