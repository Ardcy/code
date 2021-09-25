
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main(){
    int n,m;
    int dp[55][55];
    char a[55][55];
    cin>>n>>m;
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        	cin>>a[i][j];
		}
    }
	if(n==1&&m==1){
		cout<<0<<endl;return 0;
	}
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i*j==1)continue;
            if(a[i][j-1]=='R'||a[i][j-1]=='B')dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
            if(a[i-1][j]=='D'||a[i-1][j]=='B')dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
        }
    }
    cout<<dp[n][m]<<endl;
}

