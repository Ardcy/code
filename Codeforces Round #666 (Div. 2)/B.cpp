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
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	int pre = 0;
	int ans = 1e17;
	int cn = 1;
	while(1){
		int sum1 = 0;
		int p1 = 1;
		for(int i=1;i<=n;i++){
			sum1+=abs(p1-a[i]);
			p1*=cn;
			if(p1>1e14)break;
		}
//		cout<<sum1<<endl;
//		cout<<ans<<endl;
		if(p1>1e14)break;
		ans = min(ans,sum1);
		cn++;
		
	}
	cout<<ans<<endl;
	return 0;
}


