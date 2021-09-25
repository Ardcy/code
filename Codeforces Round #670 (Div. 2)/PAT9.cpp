#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
const int N = 200500;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
int inv[N],fac[N],rev[N];
void init(int n){
	fac[0]=1;rev[n]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1;i<n;i++)inv[i]=(rev[i]*fac[i-1]%mod)%mod;
}
int a[N];
int dp[N];
signed main(){
	int n;
	cin>>n;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0)cnt++;
	}
	if(cnt==n){
		cout<<"0 1 "<<n<<endl;
		return 0;
	}
	int ans = 0;int h1 = 0;
	for(int i=1;i<=n;i++){
		dp[i]= max(dp[i-1]+a[i],a[i]);
		//ans = max(ans,dp[i]);
		if(ans<dp[i]){
			ans=dp[i];
			h1 = i;
		}
	}
	int p = 0;int h2 =0;
	for(int i=h1;i>=1;i--){
		p+=a[i];
		if(p==ans){
			h2=i;
		
		}
	}
	cout<<ans<<" "<<a[h2]<<" "<<a[h1]<<endl;
	return 0;
}


