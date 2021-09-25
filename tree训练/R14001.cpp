#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const int mod = 1000000007;
int rnd(int x){return mrand()%x;}
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
VI P[105000];
int pr[105000];
int cnt[105000];
int white = 0;
int black = 0;
void dfs(int u,int f,int t){
	if(t==0)white++;
	if(t==1)black++;
	pr[u]=t;
	for(auto p:P[u]){
		if(p==f)continue;
		dfs(p,u,1-t);
	}
}
signed main(){
	int n;
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		P[u].push_back(v);P[v].push_back(u);
		cnt[u]++;
		cnt[v]++;
	}
	pr[1]=1;
	dfs(1,0,1);
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(pr[i]==0)ans+=(black-cnt[i]);
		else ans+=(white-cnt[i]);
	}
	cout<<ans/2<<endl;
	return 0;
}
