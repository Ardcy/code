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
set<int>Pr;
VI P[3000];
int ans1;
void dfs(int u,int f,int e){
	ans1=max(ans1,e);
	for(auto p:P[u]){
		if(p!=f){
			dfs(p,u,e+1);
		}
	}
	
}
signed main(){
	int n;
	cin>>n;
	int u;
	for(int i=1;i<=n;i++){
		cin>>u;
		if(u==-1){
			Pr.insert(i);
		}
		else{
			P[u].pb(i);P[i].pb(u);
		}
	}
	int ans = 0;
	for(auto p:Pr){
		ans1=0;
		dfs(p,0,1);
		ans=max(ans1,ans);
	}
	cout<<ans<<endl;
	return 0;
}
