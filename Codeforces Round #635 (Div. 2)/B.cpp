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
		int n,x,m;
		cin>>x>>n>>m;
		int f = 1;
		while((x>20)&&n){
			x/=2;x+=10;
			n--;
		}
		while((x)&&m){
			x-=10;
			m--;
		}
		if(x<=0)cout<<"YES"<<endl;else cout<<"NO"<<endl;
	}
	return 0;
}


