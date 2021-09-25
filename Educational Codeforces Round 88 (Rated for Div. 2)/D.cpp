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

int a[105000];
int dp[105000];
signed main() {
	{
		int n;
		cin>>n;
		for(int i=1; i<=n; i++)cin>>a[i];
		int ans1 = 0;
		int sum = 0;
		int ans = 0;
		int f = 0,f1 = 0;
		int ma = 0;
		for(int i=1; i<=n; i++) {
			ma = max(ma,a[i]);
			if(ma>a[i])sum+=a[i];
			ans=max(sum,ans);
			if(sum<0) {
				sum=0;
				f1 = 0;
				ma=0;
			}
			cout<<ma<<endl;
		}

		cout<<ans<<endl;

	}
	return 0;
}


