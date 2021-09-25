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
vector<PII> P[10000];
set<int>Pr;
int laabs[10000];
int col[10000];
map<PII,int>Pe;
void dfs(int u){
	col[u]=1;
	for(auto p:P[u]){
		int to = p.fi,id=p.se;
		if(col[to]==0){
			dfs(to);laabs[id]=1;
		} 
		else if(col[to]==2)laabs[id]=1;
		else {
			laabs[id]=2;
		}
	}
	col[u]=2;
}
signed main(){
	int n,m;
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		P[u].pb(mp(v,i));
		Pr.insert(u);
	}
	for(auto p:Pr){
		if(col[p]==0)
		dfs(p);
	}
	cout<<*max_element(laabs+1,laabs+m+1)<<endl;
	for(int i=1;i<=m;i++)cout<<laabs[i]<<" ";
	return 0;
}
