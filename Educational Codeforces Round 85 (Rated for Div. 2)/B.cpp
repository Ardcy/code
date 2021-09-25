#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000];
int sum[105000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			if((sum[n]-sum[i-1])/(n+1-i)>=x){
				ans=(n+1-i);
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
