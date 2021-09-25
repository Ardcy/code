#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl
#define int long long
signed main(){
		int t;int n,x,y;
		cin>>t;
		while(t--){
			
			cin>>n>>x>>y;
			int tt = 1;
			
			int y=max(x+y+1-n,tt);
			int a=min(y,n);
			cout<<a<<" "<<min(x+y-1,n)<<endl;	
		}
		
}
	

