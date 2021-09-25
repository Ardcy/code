#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1005000];
signed main(){
	int t;
	cin>>t;
	for(int ii = 1;ii<=t;ii++){
		int a,b;
		int l,r;
		int ll,rr;
		cin>>a;
		dp[0] = 0;
		int maxe = 0;
		for(int i=1;i<=a;i++){
			cin>>b;
			dp[i] = max(dp[i-1]+b,b);
			maxe = max(maxe,dp[i]);
			if(dp[i]==b)l=i,r=i;
			else r++;
			if(maxe==dp[i]){
			    ll=l;rr=r;
			}
		}
		cout<<"Case "<<ii<<":"<<endl;
		cout<<maxe<<" "<<ll<<" "<<rr<<endl;
		if(ii!=t)cout<<endl;
	}
}
