#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
const int N = 1000005,mod = 1e9+7;
int fac[N],rev[N],sz[N],ans[N],fa[N];
int n,m,res;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans=(ll)ans*a%mod;
		a=(ll)a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;rev[n]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)rev[i]=(ll)rev[i+1]*(i+1)%mod;
}
int C(int n,int m){
	if(n<0||n<m)return 0;
	else {
		return (ll)fac[n]*rev[n-m]%mod*rev[m]%mod;
	}
}
signed main(){
	int t;
	init(1000000);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			scanf("%d",&fa[i]);
			sz[i]=0;
		}
		int p = (m-1)/2-1;
		int sum = (p>=0?C(n-1,m-1):0);
		for(int i=1;i<=n-1;i++){
			int d = (ll)C(i-2,p)*C(n-i,m-2-p)%mod;
			sum+=(mod-d);
			sum%=mod;
			cout<<sum<<endl;
			ans[i]=(ll)i*sum%mod;
		}
		for(int i=1;i*2<=n;i++){
			ans[i]=(ans[i]+ans[n-i])%mod;
			if(m%2==0){
				int c = (ll)C(i,m/2)*C(n-i,m/2)%mod;
				ans[i]=(ans[i]+(ll)c*(m/2)%mod)%mod;
			}
		}
		res = 0;
		for(int u = n;u>=2;u--){
			sz[u]++;
			sz[fa[u]]+=sz[u];
			int f =min(sz[u],(int)(n-sz[u])); 
			res+=ans[f];
			res%=mod;
		}
		for(int i=1;i<n;i++)cout<<ans[i]<<endl;
		cout<<res<<endl;
	}	
}
