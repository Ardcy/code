#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200];
int dp[200];
int c[200];
signed main(){
	
	int n;
	cin>>n;
	
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){		
		if(a[i]==0)dp[i]=dp[i-1];
		else if(a[i]==3){
			dp[i]=dp[i-1]+1;
			if(c[i-1]==1)c[i]=2;
			else if(c[i-1]==2)c[i]=1;
		}
		else{
			c[i]=a[i];
			if(a[i]!=c[i-1]){
				dp[i]=dp[i-1]+1;
			}
			else c[i]=0,dp[i]=dp[i-1];
		}
		
	}
	cout<<n-dp[n]<<endl;
	return 0;
}
