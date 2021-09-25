#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[205600];
int dp[200020];
signed main(){
	int t;
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		int ans1=-1000000000000000;
		for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i];
		int dp=0;
		for(int i=1;i<n;i++){
			dp=max(a[i],dp+a[i]);
			ans1=max(dp,ans1);
		}
		dp=0;
		for(int i=2;i<=n;i++){
			dp=max(a[i],dp+a[i]);
			ans1=max(dp,ans1);
		}
		if(ans1<ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	} 
	
	return 0;
}
