#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int dp[2020][2020];
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		dp[1][i]=1;
	}
	for(int i=1;i<k;i++){
		for(int j=1;j<=n;j++){
			for(int g=j;g<=n;g+=j){
				dp[i+1][g]+=dp[i][j];
				dp[i+1][g]%=mod;
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans += dp[k][i];
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0;
}
