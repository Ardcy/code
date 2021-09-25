#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
 
 
signed main(){
	int T;
	cin>>T;
	while(T--){
		int c,h,t;
		cin>>h>>c>>t;
		if(c+h>=2*t){
			cout<<2<<endl;
		}else{
			int p = (h-t)/(2*t-c-h);
			int ans1 =p;
			int ans2 =p+1;
			int p1 = (ans1*c+ans1*h+h-ans1*t-ans1*t-t);
			int p2 = (-ans2*c-ans2*h-h+ans2*t+ans2*t+t);
			if(p1*(2*ans2+1)>p2*(2*ans1+1))cout<<ans1*2+3<<endl;else cout<<(ans1*2+1)<<endl;
		}
	}
	return 0;
}
