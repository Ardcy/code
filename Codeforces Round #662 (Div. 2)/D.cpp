#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod =99998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

char A[2005][2005];
int dp[2005][2005];
signed main(){

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%s",A[i]+1);
//	for(int i=1;i<=n;i++)cout<<A[i]+1<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)A[i][j]='a';
//	}
	
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dp[i][j]=1;
	
	for(int i=3;i<=m;i++){
		
		for(int j=1;j<=n;j++){
			if((A[j][i]==A[j][i-1])&&(A[j][i]==A[j+1][i-1])&&(A[j][i]==A[j-1][i-1])&&(A[j][i]==A[j][i-2])){
				int f = mod;
				f=min(f,dp[j][i-1]);
				f=min(f,dp[j][i-2]);
				f=min(f,dp[j-1][i-1]);
				f=min(f,dp[j+1][i-1]);
				dp[j][i]=f+1;
				
			}	
		}	
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	int ans = 0;
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)ans+=dp[i][j];
	cout<<ans<<endl;
	return 0;
}


