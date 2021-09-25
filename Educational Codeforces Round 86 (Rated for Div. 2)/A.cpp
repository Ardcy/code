#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%mod;a*=a,a%=mod;b>>=1;}return ans;};
int a[105000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,x,y;
		cin>>x>>y;
		cin>>a>>b;
		int ans = 0;
		if(b>2*a||x*y<0){
			cout<<(abs(x)+abs(y))*a<<endl;
		}
		else {
			int e = min(abs(x),abs(y));
			
			ans = b*e+a*max(abs(x),abs(y))-a*e;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}


