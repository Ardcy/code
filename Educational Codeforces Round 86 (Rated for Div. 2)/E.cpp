#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
const int N=205000;
int fac[206000];

void init(){
	fac[0]=1;
	for(int i=1;i<=N;i++){
		fac[i]=fac[i-1]*i%mod;
	}
}
int qp(int a,int b,int mod){
	int ans=1;while(b){
		if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;
	}
	return ans;
} 
int c(int n,int m){
	return fac[n]*qp((fac[m]*fac[n-m])%mod,mod-2)%mod;
}


signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)fac[i]=0;
	int ans = 0;
	
	if(k==0){
		int a = 1;
		for(int i=1;i<=n;i++){
			a*=i;a%=mod;
			
		}
		cout<<a<<endl;
	}else if(k>=n){
		cout<<0<<endl;
	}else{
		init();
		int ans = 0; 
		for(int i=0;i<=n-k;i++){
			if(i%2==1)ans-=(qp(n-k-i,n)*c(n-k,i)%mod);
			else ans+=qp(n-k-i,n)*c(n-k,i)%mod;
			ans%=mod;
		} 
		ans*= 2*c(n,n-k)%mod;
		cout<<(ans%mod+mod)%mod<<endl;	
	}
	return 0;
}


