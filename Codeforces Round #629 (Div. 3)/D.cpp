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
int a[205000];
int ci[10];
int dp[205000];
signed main(){
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int f = 1;
		dp[1]=1;
		int f1=0;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1])f1=1;
		}
		if(f1==0){
			cout<<1<<endl;
			for(int i=1;i<=n;i++)cout<<1<<" ";cout<<endl;continue;
		}
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1])dp[i]=dp[i-1],f=i;
			else dp[i]=(3-dp[i-1]);
		}
		if(dp[1]!=dp[n]){
			cout<<2<<endl;
			for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;continue;
		}
		
		if(f!=1&&a[1]!=a[n]){
			cout<<2<<endl;
			for(int i=1;i<=f-1;i++){
				cout<<dp[i]<<" ";
			}
			for(int i=f;i<=n;i++)cout<<(3-dp[i])<<" ";cout<<endl;
			continue;
		}
		cout<<3<<endl;
		for(int i=1;i<n;i++)cout<<dp[i]<<" ";
		cout<<3<<endl;
	}

	return 0;
}
