#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	int a,b,c;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		int ans = 0;
		ans+=(a+b+c);
		cout<<(ans/2)<<endl;
	}
	return 0;
}
