#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
signed main(){
	int t;
	int a,b,c,d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		if(a>b)swap(a,b);
		if(b>c)swap(b,c);
		if(a>b)swap(a,b);
		if(a==0&&b==0&&c==0){cout<<0<<endl;continue;}
		int ans = 0;
		if(a>0)ans+=1,a-=1;
		if(b>0)ans+=1,b-=1;
		if(c>0)ans+=1,c-=1;if(c>0&&b>0)ans+=1,c-=1;b-=1;
		
		if(a>0&&c>0)ans+=1,a-=1;c-=1;
		if(a>0&&b>0)ans+=1,a-=1;b-=1;
		if(a>0&&b>0&&c>0)ans+=1;
		cout<<ans<<endl;
	}
	return 0;
}
