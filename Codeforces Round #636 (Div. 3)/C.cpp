#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int a[205000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans = 0;
		int pre = a[1];
		for(int i=2;i<=n;i++){
			if(a[i]*pre>0){
				pre =  max(pre,a[i]);
			}else{
				ans+=pre;
				pre=a[i];
			}
		}
		ans+=pre;
		cout<<ans<<endl;
	}
	return 0;
}


