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
double i(double a,double b){
	return -(a/(a+b))*log((a/(a+b)))/log(2)-(b/(a+b))*log((b/(a+b)))/log(2);
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<i(a,b)<<endl;
	}
	return 0;
}


