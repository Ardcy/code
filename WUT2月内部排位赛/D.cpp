#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int yy;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans*=a;
		a*=a;
		a%=mod;
		b>>=1;
		ans%=mod;
	}
	return ans;
}
int p(int r){
	return ((((r*(r+1)%mod+mod)%mod)*(2*r+1)+mod)%mod*yy+mod)%mod;
}
int cal(int n){ 
	int ans=0;
	for(int l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		int e=p(r)-p(l-1);
		e= (e%mod+mod)%mod;
		ans+=(n/l)*(e)%mod;
	}
	return ans%mod;
}
signed main(){
	int n,m;
	cin>>n;
	yy=qp(6,mod-2);
	while(n--){
		cin>>m;
		printf("%lld\n",(cal(m)+mod)%mod);
	}
	
}

