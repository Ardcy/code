#include<bits/stdc++.h>
using namespace std;
#define int long long
int qp(int a,int b,int mod){
	int ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;
	}return ans;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int k,l,r,p;
		cin>>k>>l>>r>>p;
		if(p==2){
			if(k&1)cout<<"0"<<endl;else cout<<1<<endl;continue;
		}
		int ans = 0;
		if(!(k%p))ans=1;
		else{
			int a=qp(2,r+1,p-1),b=qp(2,l,p-1);
			a-=b;
			if(a<0)a+=(p-1);
			int c=qp(k,a,p),d=qp(k,b,p);
			if(d>1)ans=(c*d%p-1)*qp(d-1,p-2,p)%p;
			else ans=qp(2,r-l+1,p);
			if(ans<0)ans+=p;
		}
		if(k&1)ans=ans*qp((p+1)/2,r-l,p)%p;
		cout<<ans<<endl;
	}
	return 0;
}
