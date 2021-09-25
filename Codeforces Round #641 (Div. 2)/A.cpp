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
		int a,b;
		cin>>a>>b;
		
		int c=1;
		for(c=2;c<=a;c++){
			if(__gcd(c,a)!=1)
			break;
		}
		a+=c;
		//cout<<a<<endl;
		b--;
		cout<<a+2*b<<endl;
	}
	return 0;
}


