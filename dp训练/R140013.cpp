#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000];
signed main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans = 10000000;
	for(int i=1;i<n;i++){
		ans=min(ans,(i-1)+n+1-(upper_bound(a+1,a+n+1,2*a[i])-a));
	}
	cout<<ans<<endl;
	return 0;
}
