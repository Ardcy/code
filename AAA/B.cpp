#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

int dp[3][105000];
int mace(int a,int b,int c){
	return max(max(a,b),c);
}
int mane(int a,int b,int c){
	return min(min(a,b),c);
}
signed main(){
	int t;
	cin>>t;
	string s;
	while(t--){
		
		cin>>s;
		int n = s.length();
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				dp[j][i]=0;
			}
			//dp[s[i]-'0']=i;
		}
		for(int i=0;i<n;i++){
			if(i!=0)
			for(int j=0;j<3;j++){
				dp[j][i]=dp[j][i-1];
			}
			dp[s[i]-'0'-1][i]=i+1;
		}
//		for(int i=0;i<n;i++){
//			for(int j=0;j<3;j++){
//				cout<<dp[j][i]<<" ";
//			}
//			cout<<endl;
//		}
		int ans = 1e9;
		for(int i=n-1;i>=0;i--){
			if(dp[0][i]&&dp[1][i]&&dp[2][i]){
				ans=min(ans,mace(dp[0][i],dp[1][i],dp[2][i])-mane(dp[0][i],dp[1][i],dp[2][i])+1);
			}
			
		}
		if(ans==1e9)cout<<0<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}


