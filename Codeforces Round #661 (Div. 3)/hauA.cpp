#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 1e9+7;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
const int N = 2e5+10;
int fac[N],rev[N],inv[N];
void init(int n){
	fac[0]=1;rev[n]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1;i<n;i++){
		inv[i]=(rev[i]*fac[i-1]%mod)%mod;
	}
}
int a[N],pre[N],sum[N],suf[N];
signed main(){
	init(N-1);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<=n+2;i++){
			a[i]=0,pre[i]=0,sum[i]=0,suf[i]=0;
		}
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			sum[i]=a[i]+sum[i-1];
			pre[i]=pre[i-1]+i*a[i];
			sum[i]%=mod;
			pre[i]%=mod;
		}
		for(int i=n,d=1;i>=1;i--,d++)suf[d]=suf[d-1]+d*a[i],suf[d]%=mod;
		int ans = 0;
		for(int i=1;i<=n;i++){
		    int p = min(n+1-i,i);
		    int q = n+1-p;
		    int f = (pre[p]+suf[p]+(p*(sum[q-1]-sum[p])%mod+mod))%mod*inv[i]%mod;
		    ans += f;
		    ans %= mod;
		    //cout<<f<<endl;
		    
		}
		
		cout<<ans*inv[n]%mod*inv[n+1]*2%mod<<endl;
	}
	return 0;
}


