#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[300000];
int sum[300000];
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sum[1]=a[1]%k;
	for(int i=2;i<=n;i++)sum[i]=(sum[i-1]-1+a[i]+k)%k;for(int i=1;i<=10;i++)cout<<sum[i]<<" ";cout<<endl;
	sort(sum+1,sum+n+1);
	
	int cnt = 0;
	int ans = 0;
	
	for(int i=2;i<=n;i++){
		cnt = 1;
		while(sum[i]==sum[i-1])i++,cnt++;
		ans += cnt*(cnt-1)/2;
	}
	for(int i=1;i<=n;i++)if(sum[i]==k-1)ans++;
	cout<<ans<<endl;
	return 0;
}
