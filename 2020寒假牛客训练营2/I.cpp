#include<bits/stdc++.h>
using namespace std;
long long int n,a,b,c;
string s;
#define N 100050
long long int dp[N];
int main()
{
	cin>>n>>a>>b>>c>>s;
	for(int i=0;i<s.length();i++){
		dp[i] = dp[i-1];
		if(i>=3&&s.substr(i-3,4)=="nico")
			dp[i]=max(dp[i],dp[i-3]+a);
		if(i>=5&&s.substr(i-5,6)=="niconi")
			dp[i]=max(dp[i],dp[i-5]+b);
		if(i>=9&&s.substr(i-9,10)=="niconiconi")
			dp[i]=max(dp[i],dp[i-9]+c);	
	}
	cout<<dp[n-1]<<endl;
}
