#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=mod;
		a*=a;
		a%=mod;b>>=1;
	}
	return ans;
}

signed main(){
 	int n;
 	cin>>n;
 	int q;
 	cin>>q;
 	while(q--){
 		int a,b;
 		cin>>a>>b;
 		int gcd = __gcd(a,b);
 		
	 }
    return 0;
}
