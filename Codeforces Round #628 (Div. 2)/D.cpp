#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long

signed main(){
	int a,b;
	cin>>a>>b;
	if(a==b){
		if(a==0)cout<<0<<endl;
		else {
			cout<<1<<endl;
			cout<<a<<endl;
		}
	}
	else{
		int y = (b-a)/2;
		if(a>b||(b-a)%2==1)cout<<-1<<endl;
		else if(((a^y)+y)==b){
			cout<<2<<endl;
			cout<<(a^y)<<" "<<y<<endl;
		}
		else{
			cout<<3<<endl;
			cout<<a<<" "<<(b-a)/2<<" "<<(b-a)/2<<endl;	
		}	
	}
}

