#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		cout<<(c/2)*(a-b)+(c%2)*a<<endl;
	}
	return 0;
}
