#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
#define int long long

signed  main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		int ans=0;
		int p = (n-m)/(m+1),q=(n-m)%(m+1);
		
		ans = (1+n)*n/2-(1+p)*p/2*(m+1-q)-(1+p+1)*(p+1)/2*(q);
		cout<<ans<<endl;	
	}
}
