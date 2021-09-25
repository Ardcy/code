#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int cnm(int n,int m){
	int a=1,b=1; 
	m=min(m,n-m);
	for(int i=1;i<=m;i++){
		a*=n+1-i;
		b*=i;
		if(a%b==0){
			a/=b;
			b=1;
		}
	}
	return a/b;
} 
int fac[105000];
void init(){
	fac[0]=1;
	for(int i=1;i<=N;i++){
		fac[i]=fac[i-1]*i%mod;
	}
}
int e_gcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	int gcd=e_gcd(b,a%b,y,x);
	y-=a/b*x;
	return gcd;
} 
int inv(int a,int n){
	int x,y;
	e_gcd(a,n,x,y);
	return (x+n)%n;
}
int c(int n,int m){
	return fac[n]*inv((fac[m]*fac[n-m])%mod,mod)%mod;
}
int fac[105000];
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
int lucas(int n,int m,int p){
	int ans = 1;
	while(n&&m&&ans){
		ans=(ans*C(n%p,m%p))%p;
		n/=p;m/=p;
	}
	return ans;
} 

signed main(){
	cout<<C(100000,2)<<endl;
}
