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
int a[305000];
int b[305000];
int dp[305000][3];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&a[i],&b[i]);
		}
		for(int i=0;i<3;i++)dp[0][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				dp[i][j]=1e15;
				for(int k=0;k<3;k++){
					if(a[i]+j!=a[i-1]+k)dp[i][j]=min(dp[i-1][k],dp[i][j]);
//					cout<<dp[1][0]<<endl;				
				}
				dp[i][j]+=j*b[i];
			}
//			for(int j=0;j<3;j++)cout<<" "<<dp[i][j];cout<<endl;
		}
		int ans = 1e18;
		for(int i=0;i<3;i++)ans=min(ans,dp[n][i]);
		cout<<ans<<endl;
		
	} 

	return 0;
}
