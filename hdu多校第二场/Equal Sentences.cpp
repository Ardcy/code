#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int mod = 1e9+7;
int dp[105000];
signed main(){
	int t;string q;
	cin>>t;
	while(t--){
		vector<string>P;
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>q;P.pb(q);
		}
		dp[0]=1;dp[1]=1;
		int ans = 0;
		for(int i=1;i<n;i++){
			if(P[i]!=P[i-1])
				dp[i+1]=dp[i-1]+dp[i];
			else
				dp[i+1]=dp[i];
			dp[i+1]%=mod;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}


