#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[300000];
int b[300000];
signed main(){
	int t=1;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n;i++){
			a[i]=a[i]-b[i];
		}
		sort(a+1,a+n+1);
		a[0]=-100000000000;
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=(n+1-(upper_bound(a,a+n+1,-a[i])-a));
			if((upper_bound(a,a+n+1,-a[i])-a)<=i){
				ans-=1;	
			}
		}
		cout<<ans/2<<endl;		
	}
}
