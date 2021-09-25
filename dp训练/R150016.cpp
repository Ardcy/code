#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[205000][3];
const int mod = 1e9+7;
signed main(){
	int n,l,r;
	cin>>n>>l>>r;
	int a=0,b=0,c=0;
	int u1=l/3,u2=l%3;
	int y1=r/3,y2=r%3;
	if(u2==0)c=y1-u1+1,a=c-1,b=c-1;else c=y1-u1;
	if(u2==2)a=c-1,b=c;if(u2==1)a=c,b=c;
	if(y2==2)a++,b++;if(y2==1)a++;
//	cout<<a<<" "<<b<<" "<<c<<endl;
	dp[1][0]=a;dp[1][1]=b;dp[1][2]=c;
	for(int i=2;i<=n;i++){
		
		dp[i][0]=dp[i-1][1]*b+dp[i-1][0]*c+dp[i-1][2]*a;
		dp[i][1]=dp[i-1][1]*c+dp[i-1][0]*a+dp[i-1][2]*b;
		dp[i][2]=dp[i-1][1]*a+dp[i-1][0]*b+dp[i-1][2]*c;
		dp[i][0]%=mod;dp[i][1]%=mod;dp[i][2]%=mod;
	}
	cout<<dp[n][2]<<endl;
}

