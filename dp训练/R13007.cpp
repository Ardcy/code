#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000],b[105000];
int pre[105000],p[105000];
int h[105000];
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+b[i]*a[i];
		p[i]=p[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		h[i]=h[i+1]+b[i]*a[i];
	}
	int ans = 0;
	for(int i=1;i<=n-k+1;i++){
		ans = max(ans,pre[i-1]+p[i+k-1]-p[i-1]+h[i+k]);
	}
	cout<<ans<<endl;
	return 0;
}
