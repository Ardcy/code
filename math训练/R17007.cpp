#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans+=(4*i-2*n-1)*a[i];
	}
	int g = __gcd(ans,n);
	cout<<ans/g<<" "<<n/g<<endl;
}
