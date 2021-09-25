#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[305000];
int b[305000];
int c[305000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i],&b[i]);
		
		int sum = 0;
		int l1 = 0;
		for(int i=1;i<=n;i++){
			if(i==1)c[i]=max(a[1]-b[n],l1);
			else c[i]=max(a[i]-b[i-1],l1);
			sum+=c[i];
		}
		//cout<<sum<<endl;
		int ans = 1e18;
		for(int i=1;i<=n;i++){
			ans=min(a[i]+sum-c[i],ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
