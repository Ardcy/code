#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[10500000][2];
const int mod = 1e9+7;
signed main(){
	int n;
	cin>>n;
	dp[1][0]=1;
	for(int i=2;i<=n;i++){
		dp[i][1]=dp[i-1][1];
		dp[i][0]=dp[i-1][0];
		if(i%2==0){
			dp[i][1]+=dp[i-1][0];
			dp[i][1]++;
			dp[i][1]%=mod;
		}else{
			dp[i][0]+=dp[i-1][1];
			dp[i][0]++;
			dp[i][0]%mod;
		} 
	}
	cout<<(dp[n][0]+dp[n][1])%mod<<endl;
	return 0;
}
