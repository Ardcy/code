#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int dp[4000][4000];
const int mod = 998244353;
signed main(){
	string s,t;
	cin>>s>>t;
	s=' '+s;
	int n=s.length();
	int m=t.length();
	int ans = 0;
	for(int i=0;i<=m;i++)dp[0][i]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i]==t[j])dp[i][j]=dp[i-1][j+1];
			if(i+j>m||s[i]==t[i+j-1])dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
		}
		dp[i][m]=(dp[i-1][m]*(int)2)%mod;
		if(i>=m)ans=(ans+dp[i][0])%mod;
	}
	cout<<ans<<endl; 
	return 0;
}


