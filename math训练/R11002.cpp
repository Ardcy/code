#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin>>n;
	int ans = 0,ans1 = 1 ;
	for(int i=1;i<=n;i++)ans1=(2*ans1),ans+=ans1;cout<<ans<<endl;
	return 0;
}
