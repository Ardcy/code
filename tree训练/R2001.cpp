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
VI P[2000];
int d[2000];
signed main(){
	int n;
	cin>>n;
	int u;
	for(int i=2;i<=n;i++){
		cin>>u;
		P[u].pb(i);
		P[i].pb(u);
		d[u]++;
	} 
	int  flag = 0;
	for(int i=1;i<=n-1;i++){
		int cnt = 0;
		
		for(auto p:P[i]){
			if(d[p]==0)cnt++;
		}
		if(d[i]>0&&cnt==0||cnt==1||cnt==2)flag=1;
	
	}
	if(flag)cout<<"No"<<endl;else cout<<"Yes"<<endl;
	return 0;
}
