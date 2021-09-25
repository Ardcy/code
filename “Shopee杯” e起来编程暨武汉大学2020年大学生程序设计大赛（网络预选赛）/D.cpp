#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
char a[2005][2005];
int dp[2005][2005];
signed main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m,ans=1;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i]+1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if((a[i][j]==a[i-1][j-1])&&(a[i][j]==a[i-1][j])&&(a[i][j]==a[i][j-1])){
					dp[i][j]=min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1;
					ans=max(ans,dp[i][j]);
				}
				else  dp[i][j]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

