#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>d>>c>>b;
		cout<<min(a-1,abs(b-c)+d)<<endl;
	}
}
