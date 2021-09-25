#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a>c)cout<<c<<endl;
		else cout<<(b/c+1)*c<<endl;
	} 
	return 0;
} 
