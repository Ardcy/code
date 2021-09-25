#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		
		
		if( (c-d)>n*(a+b)||(c+d)<n*(a-b) ){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}


