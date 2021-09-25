
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod =998244353;
const int N=10005000;
int fac[10005000];
void init(){
	fac[0]=1;
	for(int i=1;i<=N;i++){
		fac[i]=fac[i-1]*i%mod;
	}
}
int qp(int a,int b,int mod){
	a%=mod;
	int ans=1;while(b){
		if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;
	}
	return ans;
} 
//int c(int n,int m){
//	int u = qp((fac[m]*fac[n-m])%mod,mod-2,mod);
//	
//	return fac[n]*u%mod;
//}

int cnm(int n,int m){
	int a=1,b=1; 
	m=min(m,n-m);
	for(int i=1;i<=m;i++){
		a*=n+1-i;
		a%=mod;
		b*=i;
		b%=mod;
	}
	int cc =qp((b)%mod,mod-2,mod);
	return a*cc;
} 
signed main(){
	init();
	int t;
	
	cin>>t;
	while(t--){
		int m,k;
		cin>>m>>k;
		int ans1 = (qp(k,m,mod)+k)%mod;
		//cout<<ans1<<endl;
		
		int ans2 = 2*cnm(m+k-1,k-1)%mod;
		//cout<<ans2<<endl; 
		
		cout<<(ans1-ans2+mod)%mod<<endl;
	}
	
}
