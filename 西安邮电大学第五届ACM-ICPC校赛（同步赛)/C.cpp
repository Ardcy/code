#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

int ans = 0;
vector<int>P[1000];
int F[120][150];
int a[105000];
void dfs(int x,int pre){
	for(auto p1:P[x]){
		if(p1==pre)continue;
		dfs(p1,x);
		set<int>U;
		for(int i=0;i<=127;i++){
			for(int j=0;j<=127;j++){
				if(x!=0&&F[x][i]&&F[p1][j]){		
					U.insert(i^j);
					ans=max(i^j,ans);
				}
			}	
		}
		for(auto pp:U){
			F[x][pp]=1;
		}
	}
}
int sum[105000];
int sum1[105000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		F[i][a[i]]=1;
		ans = max(a[i],ans);
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		P[u].pb(v);P[v].pb(u);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}


