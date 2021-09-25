#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
const int N = 200500;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};
int inv[N],fac[N],rev[N];
void init(int n) {
	fac[0]=1;
	rev[n]=1;
	for(int i=1; i<=n; i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1; i>=0; i--)rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1; i<n; i++)inv[i]=(rev[i]*fac[i-1]%mod)%mod;
}
int dp[N][2];
int u,v,p,q,ee;
void solve(string s) {

	
	int l = s.length();
	
	for(int i=0; i<l; i++) {
		dp[i][1]=0;
		dp[i][0]=0;
	}

	
	for(int i=0; i<l; i++) {

		if(s[i]=='R') {
			dp[i+1][1]=dp[i][0];
			
			if(i>0)dp[i+1][0]=min(dp[i][1],dp[i-1][1]);
			else dp[i+1][0]=dp[i][1];
			dp[i+1][0]+=1;
		} else {
			if(i>0)dp[i+1][0]=min(dp[i][1],dp[i-1][1]);
			else dp[i+1][0]=dp[i][1];
			dp[i+1][1]=dp[i][0]+1;
		}

	}
	u=dp[l][1],v=dp[l][0],p=dp[l-1][1],q=dp[l-1][0],ee=dp[l-2][0];
	//return dp[l-1][1];
}


signed main() {
	int t;
	cin>>t;
	string s;
	while(t--) {
		int n;
		cin>>n;
		cin>>s;

		int ans = 1e8;
		string f = "LL";
		//case1:LL
		
		int cnt; 
		cnt = 0;
		for(int i=0;i<2;i++){
			if(s[i]!=f[i])cnt++; 
		}
		
		solve(s.substr(2));
		ans = min(ans,cnt+u);
		cout<<ans<<endl;
		//case2:RR
		f="RR";
		cnt = 0;
		for(int i=0;i<2;i++){
			if(s[i]!=f[i])cnt++; 
		}
		cnt+=(s[2]!='L') ;
		solve(s.substr(3));
		ans = min(ans,cnt+v);cout<<ans<<endl;
		//case3:LR
		f="LR";
		cnt = 0;
		for(int i=0;i<2;i++){
			if(s[i]!=f[i])cnt++; 
		}
		
		solve(s.substr(2));
		
		//cout<<ee<<" "<<q<<endl;
		ans = min(ans,cnt+min(v,q));cout<<ans<<endl;
		
		
		//case4:RL
		f="RL";
		cnt = 0;
		for(int i=0;i<2;i++){
			if(s[i]!=f[i])cnt++; 
		}
		
		solve(s.substr(2));
		//cout<<u<<" "<<v<<endl;
		//cout<<v<<"  -  "<<q<<endl;
		ans = min(ans,cnt+min(q,v));
		
		cout<<ans<<endl;
	/*
	2
5
RRRRR
1
*/	
		
		
		

	}
	return 0;
}


