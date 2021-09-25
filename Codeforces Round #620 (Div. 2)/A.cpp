#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
#define int long long

signed  main(){
	int T;
	cin>>T;
	while(T--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if((b-a)%(c+d)==0)cout<<(b-a)/(c+d)<<endl;		
		else cout<<-1<<endl;
	}
}
