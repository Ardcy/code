#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
signed main(){
	int n,t;
	int a,b;
	int sum = 0;
	int f= 0;
	cin>>t;
	while(t--){
		sum = 0;
		
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			if(i==1){
				cin>>f;
				sum+=f;	
			}
			else {
				cin>>n;
				sum+=n;
			}
			
			
		}
		if(sum>=b)cout<<b<<endl;
		else cout<<sum<<endl;
	}
	
}
