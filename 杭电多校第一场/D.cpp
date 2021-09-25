#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
#define mod 1000000009
#define N 100050
#define G5 383008016
ll fac[N],inv[N];
ll P,Q;
ll qp(ll x,ll y) {
	x=(x%mod+mod)%mod;
	ll re=1; for(;y;y>>=1ll,x=x*x%mod) if(y&1ll) re=re*x%mod; return re;
}
void init() {
	int i;
	for(fac[0]=1,i=1;i<=100000;i++) fac[i]=fac[i-1]*i%mod;
	inv[100000]=qp(fac[100000],mod-2);
	for(i=99999;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(ll n,ll m) {
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll Sum(ll x,ll n) {
	if(x==1) return n%mod;
	if(x==0) return 0;
	return (qp(x,n+1)-x)%mod*qp(x-1,mod-2)%mod;
}
ll solve(ll n,int K) {
	int j; ll ans=0;
	for(j=0;j<=K;j++) {
		int opt=((K-j)&1)?-1:1;
		ll = 
		ll t1=C(K,j),t2=opt,t3=Sum(qp(P,j)*qp(Q,K-j)%mod,n);
		
		ans=((ans+t1*t2%mod*t3%mod)%mod+mod)%mod;
	}
	return ans;
}
int main() {
	init();
	ll i2=qp(2,mod-2);
	P=(1+G5)*i2%mod; Q=((1-G5)*i2%mod+mod)%mod;
	int T;
	ll n; int K;
	scanf("%d",&T);
	ll ig5=qp(G5,mod-2);
	while(T--) {
		scanf("%lld%d",&n,&K);
		printf("%lld\n",qp(ig5,K)*solve(n,K)%mod);
	}
}
