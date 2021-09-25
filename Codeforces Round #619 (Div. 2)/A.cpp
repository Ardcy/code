#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
#define int long long

signed  main(){
	int T;
	cin>>T;
	while(T--){
		string a,b,c;
		cin>>a>>b>>c;
		int n = a.size();
		int f = 0;
		for(int i=0;i<n;i++){
			if(a[i]!=c[i]&&b[i]!=c[i])f=1;
		}
		if(f==1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;		
	}
}
