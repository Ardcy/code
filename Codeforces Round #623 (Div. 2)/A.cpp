#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
signed main(){
	int t;
	int a,b,c,d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		
		cout<<max(max(a-1-c,c)*b,a*max(b-1-d,d))<<endl;
	}
	return 0;
}
