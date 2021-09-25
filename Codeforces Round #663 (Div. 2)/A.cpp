#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6000005,mod = 998244353;
int n,m,res;
int qp(int a,int b){int ans = 1;while(b){if(b&1)ans=ans*a%mod;a=a*a%mod;b>>=1;}return ans;}
int inv[N],fac[N],rev[N];
void init(int n){
	fac[0]=1;rev[n]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1;i<n;i++)inv[i]=(rev[i]*fac[i-1]%mod)%mod;
}
signed main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%lld",&n);
	}
	
}
