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
const int maxn = 2e5 +10;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-6;

signed main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    
	int t;
	cin>>t;
	if(t==0)cout<<0<<endl;
	else cout<<(2+t)/2<<endl;
	return 0;
}


