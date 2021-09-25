#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100500
#define debug(x) cerr<<#x<<'='<<x<<endl
const int mod=1e9+7;
int a[N];
int b[N];
int dp[N]={0};
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]*((upper_bound(a,a+n+1,b[i])-a-1)-(i-1));
		dp[i]%=mod;
	}
	cout<<dp[n]<<endl;
}
