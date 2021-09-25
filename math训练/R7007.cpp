#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin>>t;
	while(t--){
		int b,p,f,a,c;
		cin>>b>>p>>f>>a>>c;
		if(c>a)cout<<(min(b/2,f)*c+min(p,(b-2*(min(b/2,f)))/2)*a)<<endl;
		else cout<<(min(b/2,p)*a+min(f,(b-2*(min(b/2,p)))/2)*c)<<endl;
	}
	return 0;
}
