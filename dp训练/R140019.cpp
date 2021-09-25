#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200008];
signed main(){
	int t,n,p,k;
	cin>>t;
	while(t--){
		cin>>n>>p>>k; 
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		a[n+1]=10000000000;
		int ans=0;
		int in = 0;
		for(int i=1;i<=n+1;i++){
			ans+=a[i];
			if(ans>p){in=i;break;}
		}
		if(ans-a[in-1]<=p)cout<<in<<endl;else cout<<in-1<<endl;
	}
	return 0;
}
