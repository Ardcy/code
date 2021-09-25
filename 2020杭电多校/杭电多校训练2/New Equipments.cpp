#include<bits/stdc++.h>
#define reg register
#define ios ios::sync_with_stdio()
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-10;
const int maxn = 50+10;
const int maxv = maxn + maxn*100;
const int maxe = maxn*100*maxn;
const double pi = acos(-1.0);
const ll mod = 1e9+7;
#define int long long
ll a[maxn],b[maxn];
ll c[maxn];

struct Edge{
	int to;
	int cost;
	int cap;
	int next;
}edges[maxe];
int head[maxv],tot = 0;
int pre[maxv];
long long dis[maxv];
bool vis[maxv];
void addedge(int u,int v, ll cost, int cap){
	edges[tot] = {v,cost,cap,head[u]};
	head[u] = tot++;
} 
void addedges(int u,int v,ll cost, int cap){
	addedge(u,v,cost,cap);
	addedge(v,u,-cost,0);
}
bool spfa(int s,int t){
	for(int i=0;i< maxv;++i){
		dis[i] = inf;
		vis[i] = 0;
		pre[i] = -1;
	}
	queue<int>que;
	dis[s] = 0;
	que.push(s);
	vis[s] = 1;
	while(que.size()){
		int u = que.front();
		que.pop();
		vis[u] = 0;
		for(int i=head[u];~i;i=edges[i].next){
			int v = edges[i].to;
			Edge &e = edges[i];
			if(e.cap > 0 && dis[v] > dis[u] + e.cost){
				pre[v] = i;
				dis[v] = dis[u] + e.cost;
				if(!vis[v]){
					que.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	return ~pre[t];
}
void init(){
	tot = 0;
	memset(head,-1,sizeof(head));
}
signed main(){
	//ios;
	int t;
	cin >> t;
	while(t--){
		init();
		int n,m;
		scanf("%lld%lld",&n,&m);
		map<int,int>mp;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		}
		int S = 0,T = maxv - 1;
		int cntv = n+1;
		for(int i=1;i<=n;i++){
			addedges(S,i,0,1);
			int mx = -b[i]/(2*a[i]);
			for(int j=max(1ll,mx - 50),cnt = 0;cnt <=100 && j<=m;++j,++cnt){
				if(!mp[j])mp[j] = cntv++;
				addedges(i,mp[j],1ll*j*j*a[i]+b[i]*j+c[i],1);
			}
		}
		for(auto it:mp){
			addedges(it.second,T,0,1);
		}
		ll cost = 0;
		for(int i=1;i<=n;i++){
			spfa(S,T);
			int f = 1e9;
			for(int i=pre[T];~i;i=pre[edges[i^1].to])
				f = min(f,edges[i].cap);
			for(int i=pre[T];~i;i=pre[edges[i^1].to]){
				edges[i].cap -=f;
				edges[i^1].cap +=f;
				cost += f*edges[i].cost;
			}
			printf("%lld%c",cost,i==n?'\n':' ');
		}
	}
}