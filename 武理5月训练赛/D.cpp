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
const int maxn = 2e5 +10;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-6;

int f(int x){
	int res=0;
	while(x){
		int u = x%10;
		x/=10;
		if(u==4||u==5)res+=2;
		else res+=1;
	}
	return res;
}
signed main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);


	int n;
	cin>>n;
	int ans = 0;
	for(int i=1; i<=n; i++) {
		ans+=f(i);
	}
	cout<<ans<<endl;
	return 0;
}

