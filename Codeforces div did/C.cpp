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

int a[1005];
signed main(){
	for(int i=1;i<=1000000;i++){
		a[i*i%1000]=1;
	}
	for(int i=1;i<=100;i++)cout<<i<<" = "<<a[i]<<endl;
	return 0;
}


