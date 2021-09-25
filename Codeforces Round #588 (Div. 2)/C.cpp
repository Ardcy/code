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
VI P[10];
map<PII,int>Pe;
set<int>Pr;
void dfs(int v){
	for(auto p:P[v]){
		if(Pe[mp(v,p)]!=1&&Pr.find(p)!=Pr.end()){
			Pe[mp(v,p)]=1,Pe[mp(p,v)]=1;
			dfs(p);	
		}
	}	
}
set<int>y;
signed main(){
	int n,m;
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		P[u].pb(v);P[v].pb(u);
		y.insert(u);y.insert(v);
	}
	if(SZ(y)<=6){
		cout<<m<<endl;
		return 0;
	}
	else {
		int ans = 0;
		for(int i=1;i<=7;i++){
			for(int j=i+1;j<=7;j++){
				int ans1=m;
				for(auto p:P[i]){
					int f = 1;
					for(auto q:P[j]){
						if(p==q)f=0;
					}
					if(f==0)ans1--;
				}
				ans=max(ans,ans1);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
