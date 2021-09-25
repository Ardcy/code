#include<bits/stdc++.h>
using namespace std;
#define N 2002
const int mod =1e9+7;
int qpow(int a,int b){
	int ans =1;
	while(b){
		if(b&1){
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return ans;
}
int p[N];
int dp[N][N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=(dp[i-1][0]*(1+mod-p[i])%mod);
		for(int j=1;j<=i;j++){
			dp[i][j]=(dp[i-1][j]*(1+mod-p[i])%mod+dp[i-1][j-1]*(p[i])%mod)%mod;
		}
	}
	for(int i=0;i<=n;i++){
		cout<<dp[n][i]<<" ";
	}
	cout<<endl;
}
