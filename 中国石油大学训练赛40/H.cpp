#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x;

signed main(){
	cin>>x;
	int n,ans=10000;
	while(x>=100){
		n=x%1000;
		ans=min(ans,abs(n-753));
		x/=10;
	}
	cout<<ans<<endl;
}

