#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N = 59;
bool vis[N],lose[N][N];
int n,k,u,v,w,ans;
int mp[N][N],path[N],dis[N];
void dijkstra(){
	memset(path,0,sizeof(path));
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[1]=0,path[1]=0;
	for(int i=1;i<n;i++){
		int d = INF,f = 0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]<d){
				d = dis[i],f = i;
			}
			vis[f] = 1;
		}
		for(int j=1;j<=n;j++){
			if(dis[f] + mp[f][j] < dis[j]&&!lose[f][j]){
				dis[j] = dis[f] + mp[f][j];
				path[j] = f;
			}
		}
	}
}
void dfs(int x){
	dijkstra();
	if(x==k+1){
		ans = max(ans,dis[n]);
		return;
	}
	for(int i=n,pre = n;i;i=path[i]){
		lose[i][pre] = lose[pre][i] = 1;
		dfs(x+1);
		lose[i][pre] = lose[pre][i] = 0;
		pre = i;
	}
	return;
}
void solve(){
	scanf("%d%d",&n,&k);
	k--;
	memset(mp,INF,sizeof(mp));
	memset(lose,0,sizeof(lose));
	ans = 0;
	for(int i=1;i<=n;i++){
		mp[i][i] = 0;
	}
	for(int i=1;i<=n*(n-1)/2;i++){
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v] = mp[v][u] = w;
	}
	dfs(1);
	cout << ans << endl;
	return;
}
signed main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}

}