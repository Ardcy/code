#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int a,b,c,x,y,z;
	cin>>a>>b>>c>>x>>y>>z;
	int ans = 0;
	
	ans += min(a,y)+min(b,z)+min(c,x);
	cout<<ans<<endl; 
}
