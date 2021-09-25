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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
	}
	return 0;
}


