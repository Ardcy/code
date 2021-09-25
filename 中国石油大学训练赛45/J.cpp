#include<bits/stdc++.h>
using namespace std;
#define int long long
int co(int a){
	int ans=0;
	while(a){
		ans++;a/=10;
	}
	return ans;
}
signed  main(){
	int a,b,x;
	cin>>a>>b>>x;
	int ans = 0;
	for(int i=18;i>=1;i--){
		ans = (x-b*i)/a;
		if((ans>0)&&co(ans)==i){if(ans>1e9)cout<<1000000000<<endl;else cout<<ans<<endl;return 0;}
	}
	cout<<0<<endl; 
	return 0;
}
