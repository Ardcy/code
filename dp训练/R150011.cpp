#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[300060][2];
int a[305000];
int b[305000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]>0)a[i]=a[i-1]+1;else a[i]=a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(b[i]>0){
			dp[i][0]=dp[i-1][0]+1;
			dp[i][1]=dp[i-1][1];
		}
		else{
			dp[i][0]=dp[i-1][1];
			dp[i][1]=dp[i-1][0]+1;
		}
		
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++)ans1+=dp[i][0],ans2+=dp[i][1];
	cout<<ans2<<" "<<ans1<<endl;
	return 0;
}
