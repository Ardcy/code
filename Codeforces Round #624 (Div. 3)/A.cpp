#include<bits/stdc++.h>
using namespace std;
#define int long long
#define de(x) cerr<<#x<<"="<<x<<endl
void solve(){
	
}
signed main(){
	int t;
	int a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a==b)cout<<0<<endl;
		else if(a<b&&(b-a)%2==1)cout<<1<<endl;
		else if(a>b&&(a-b)%2==0)cout<<1<<endl;
		else cout<<2<<endl;
	}	
} 
