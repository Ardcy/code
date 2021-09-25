#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n;
	int ans = 0;
	int ma = 0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int u;
		cin>>u;
		ans+=u;
		ma=max(ma,u);
	}
	cout<<ma*n-ans<<endl;
}
