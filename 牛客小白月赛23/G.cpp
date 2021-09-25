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
vector<PII> P[105000];
int de[105000];
int yt[105000];
void dfs(int u,int from,int ye){
	
	for(auto p:P[u]){
		
//		cout<<"p.se() = "<<p.se<<" p.fi() = "<<p.fi<<endl;
		if(p.fi!=from)de[p.se]=ye,dfs(p.fi,u,++ye);
	}
	
}
void dfs2(int u,int from,int ye){
	
	for(auto p:P[u]){
		
//		cout<<"p.se() = "<<p.se<<" p.fi() = "<<p.fi<<endl;
		if(p.fi!=from)de[p.se]=ye,dfs(p.fi,u,++ye);
	}
	
}
int det[105000];
int e[105000];
signed main(){
	int n;
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		P[u].pb(mp(v,i));P[v].pb(mp(u,i));
		det[u]++;
		det[v]++;
	}
	int y;
	for(int i=1;i<=n;i++){
		if(det[i]==1){
			y=i;break;
		}
	}
	
	dfs(y,-1,1);
	dfs2(y,-1,1);
	for(int i=1;i<n;i++){
		e[i]=de[i]*(n-de[i]);
	}
	sort(e+1,e+n);
//	for(int i=1;i<n;i++)cout<<de[i]<<" ";
//	cout<<endl;
	int ans = 0;
	for(int i=1;i<n;i++){
		ans+=e[i]*(n-i);
	}
	cout<<ans<<endl;
	return 0;
}
