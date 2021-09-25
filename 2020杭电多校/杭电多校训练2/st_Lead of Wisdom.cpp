#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 110;
int n,m;
int cnt[N],nxt[N];
int e[N][N][5];
int ans;
void dfs(int x,int a,int b,int c,int d){
	if(x > m){
		int temp = a*b*c*d;
		ans = max(ans,temp);
		return;
	}
	if(!cnt[x]){
		dfs(nxt[x],a,b,c,d);
		return;
	}
	int n = cnt[x];
	for(int i=1;i<=n;i++){
		dfs(x+1,a+e[x][i][0],b+e[x][i][1],c+e[x][i][2],d+e[x][i][3]);
	}
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int x;
		for(int i=0;i<=n;i++){
			cnt[i] = 0;
		}
		for(int j=0;j<n;j++){
			cin >> x;
			cnt[x]++;
			for(int i=0;i<4;i++){
				cin >> e[x][cnt[x]][i];
			}
		}
		x = m+1;
		for(int i=m;i;i--){
			nxt[i] = x;
			if(cnt[i])x=i;
		}
		ans = 100*100*100*100;
		dfs(1,100,100,100,100);
		cout << ans << endl;
	}
}