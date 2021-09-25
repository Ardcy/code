#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n,m;
	cin >> n >> m;
	if(n>m)swap(n,m);
	int ans = (n+1)*n*m  - (n+m)*(1+n)*n/2 + n*(n+1)*(2*n+1)/6;
	cout << ans << endl;
}
signed main(){
	int t;
	cin >> t;
	while(t--)solve();
	
}