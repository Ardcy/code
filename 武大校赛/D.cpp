#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
const int mod = 1e9+7;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;b>>=1;
	}
	return ans;
}
signed main(){
	int t;
	cin>>t;

	while(t--){
		int m,n;
		cin>>n>>m;
		cout<<(m*qp(2,n-1)%mod)<<endl;
	}
	return 0;
}


