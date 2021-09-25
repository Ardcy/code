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

int p(int u){
	int res = 0;
	for(int i=1;i<=u;i++){
		
		if((u*u+1)%i==0)res++;
	}
	return res;
}
signed main(){
	int t;
	for(int i=1;i<=100;i++)cout<<p(i)<<endl;
	return 0;
}


