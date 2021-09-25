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
int a[205000];
int h[105000];
vector<int>P[105000];
int Flag = 1;
int C[105000];//幸福指数的人数 
int D[105000];
int n,m;
int dp[105000];
void dfs1(int x,int pre){

	for(auto p:P[x]){
		if(p!=pre)
		{
		    dfs1(p,x);
			dp[x]+=dp[p];
		}
	}
	dp[x]+=a[x];
}

void dfs2(int x,int pre){
	int ans = 0; 
	for(auto p:P[x]){
		if(p!=pre){	dfs2(p,x);
		ans+=h[p];
		a[x]+=a[p];
		}
	}
	h[x]+=a[x];
	if(h[x]%2==1)Flag=0;
	if(h[x]>2*(a[x]))Flag=0;
	if(h[x]<ans)Flag=0;
//	C[x]=(h[x]+dp[x])/2;
//	
//	if((h[x]+dp[x])%2==1)Flag=0;
//	
//	if((-h[x]+dp[x])%2==1)Flag=0;
//	
//	if(C[x]<0||C[x]>dp[x])Flag=0;
//	if(C[x]<ans||ans>dp[x])Flag=0;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		Flag = 1;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i],C[i]=D[i]=0,dp[i]=0;
		for(int i=1;i<=n;i++)cin>>h[i];
		for(int i=1;i<=n;i++)P[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			P[u].pb(v);P[v].pb(u);
		}
		dfs1(1,-1);
		dfs2(1,-1);
		if(Flag)cout<<"YES"<<endl;else cout<<"NO"<<endl;
	
	}
	return 0;
}


