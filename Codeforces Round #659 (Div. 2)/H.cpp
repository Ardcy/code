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
int a[205000];

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum = 0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		int ans = 0;
		for(int i=1;i<=n;i++){
			ans+=(i-1)*a[i];
			ans-=(n-i)*a[i];
		}
		cout<<(ans<<endl;
	}
	return 0;
}


