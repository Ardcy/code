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
	int n;
	cin>>n;
	int cnt =0;
	int p=1e9-1;
	for(int i=1,u; i<=n; i++) {

		cin>>u;
		if(u%2==1) {
			cnt++;
			p=min(p,u);
		}

		ans+=u;

	}
	if(cnt%2==1) {
		ans-=p;
	}
	cout<<ans<<endl;
}


