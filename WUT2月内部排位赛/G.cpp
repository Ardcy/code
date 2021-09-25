#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
const int mod = 1e9+7;
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
signed main(){
	int t;
	int a;
	cin>>t;
	while(t--){
		cin>>a;
		if(a==1)cout<<0<<endl;
		int ans = qp(2,a);
		//debug(ans);
		if(a!=1)cout<<((ans-1-a)%mod+mod)%mod<<endl;
	}
}
