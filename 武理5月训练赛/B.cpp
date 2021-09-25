#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e18;
int qp(int a,int b) {	int ans=1;while(b) {	if(b&1)ans*=a,ans%=mod;	a*=a,a%=mod;	b>>=1;}	return ans;};
int f(int x) {
	int res=0;
	if(x==0)return 1;
	while(x) {
		int u = x%10;
		x/=10;
		if(u==4||u==5)res+=2;
		else res+=1;
	}
	return res;
}
int pre[10],ans=0,n,y=0,h=10;
signed main() {
	pre[0]=1;
	for(int i=1; i<10; i++)pre[i]=pre[i-1]+f(i);
	cin>>n;
	for(int i=1; i<=17; i++) {
		int f1 = qp(h,i);
		if(f1>n)break;
		ans+=(n%f1+1)*f((n%(10*f1))/f1);
		if((n%(10*f1))/f1!=0){
			ans+=f1*pre[(n%(10*f1))/f1-1];
		} 
		ans+=-f1*f(0)+((n/(10*f1))*f1)*pre[9];
	}
	ans+=pre[(n%10)]+n/10*pre[9];
	cout<<ans-1<<endl;
	return 0;
}
     

