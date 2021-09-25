#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200000];
int sum[200000];
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		sum[i]=(sum[i-1]+a[i])%m;
	}
	sort(sum+1,sum+n+1);
	int ans=0;
	for(int i=2;i<=n;i++){
		int cnt=1;
		while(sum[i]==sum[i-1]){
			cnt++;i++;
		}
		ans+=(cnt-1)*cnt/2;
	}
	for(int i=1;i<=n;i++){
		if(sum[i]==0)
		ans+=1;
	}
	cout<<ans<<endl;
}
