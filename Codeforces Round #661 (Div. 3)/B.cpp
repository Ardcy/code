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


signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>P,Q;
		int u,f=1e10+1,f1=1e10+1; 
		for(int i=1;i<=n;i++)cin>>u,P.pb(u),f=min(f,u);
		for(int i=1;i<=n;i++)cin>>u,Q.pb(u),f1=min(f1,u);
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=max(P[i]-f,Q[i]-f1);
		}
		cout<<ans<<endl;
		
	}
	return 0;
}


