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
map<int,int>P;
int a[10000];
int b[10000];
signed main(){
	int n;
	cin>>n;
	int u;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		P[a[i]]++;
	}
	for(int i=1;i<=n;i++)cin>>b[i];
	int ans = 0,ans1=0;
	set<int>Pr;
	for(int i=1;i<=n;i++){
		
		if(P[a[i]]>=2){
			for(int j=1;j<=n;j++){
				if((a[i]|a[j])==a[i])Pr.insert(j);
				
			}
			
		}
		
	}
	for(auto p:Pr)ans+=b[p];
	cout<<ans<<endl;
	return 0;
}
