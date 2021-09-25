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
		int u;
		vector<int>P;
		for(int i=1;i<=n;i++)cin>>u,P.pb(u);
		sort(P.begin(),P.end());
		int f=1;
		for(int i=1;i<n;i++){
			if(P[i]-P[i-1]>1)f=0;
		}
		if(f)cout<<"YES"<<endl;else cout<<"NO"<<endl;
	}
	return 0;
}


