#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define int long long
signed main(){
	int n,m;
	cin>>n>>m;
	
	int ans = (n-1)*m +(m-1)*n*2;
	int a,b,c,d;
	int cnt = 0;
	while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d)){
		if(a>c)swap(a,c),swap(b,d);
		if(a==c&&b>d)swap(b,d);
		
		if(P[e]!=1&&a==c)ans-=2;
		else if((P[e]!=1&&a!=c))ans-=1;
		P[e]=1;
	}
	cout<<ans<<endl;
	return 0;
}
