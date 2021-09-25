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

int b[105000];
int n,a,r,m;
int cal(int rr){
	int f1=0,f2=0;
	for(int i=1;i<=n;i++){
		if(b[i]>=rr)f1+=(b[i]-rr);
		else f2+=(rr-b[i]);
	}
	int f3=min(f2,f1);
	f2-=f3;f1-=f3;
	return r*f1+a*f2+m*f3;
}
int sanfen(int l,int r){
	
	while(l<r){
		int midl = l+(r-l)/3;
		int midr = l+(2*r-2*l+2)/3;
		if(cal(midl)>cal(midr))l=midl+1;
		else r=midr-1;
		
	}
	return l;
}
signed main(){
	cin>>n>>a>>r>>m;
	for(int i=1;i<=n;i++)cin>>b[i];
	m=min(m,a+r);
	sort(b+1,b+n+1);

	cout<<sanfen(0l,1e10l)<<endl;
		return 0;
}

/*
4 20 70 38 
1 100 10000 100000
*/ 
