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
	int t;
	cin>>t;
	while(t--){
		int a,b,n;
		cin>>a>>b>>n;
		if(a>b)swap(a,b);
		int cnt = 0;
		while(a<=n&&b<=n){
			cnt++;
			if(a>b)swap(a,b);
			a = a+b;
			//cout<<a<<" "<<b<<endl;
		}
		cout<<(cnt)<<endl;
		
	}
	return 0;
}


