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
		int n;
		cin>>n;
		if(n==1)cout<<26<<endl;
		else if(n==2)cout<<676<<endl;
		else if(n==3)cout<<(676*26)<<endl;
		else cout<<(26*25*24)<<endl;
	}
	return 0;
}


