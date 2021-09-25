#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};


signed main() {
	int t;
	cin>>t;
	while(t--) {
		int a,b;
		cin>>a>>b;
		if(a<=b) {
			cout<<1<<endl;
		} else {
			int ans = 1e9;
			int tt  = sqrt(a);
			int qq = min(b,tt);
			int f = 0;
			for(int i=1; i<=tt+1; i++) {
				if(a%i==0){
					if(a/i<=b){
						f=1;	
						ans=min(i,ans);
						break;
					} else if(i<=b){
						f=1;
						ans=min(ans,a/i);
					}
				}
				
			}
			if(f)
			cout<<ans<<endl;
			else{
				cout<<a<<endl;
			}
		}
	}
	return 0;
}


