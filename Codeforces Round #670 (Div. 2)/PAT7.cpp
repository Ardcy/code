#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
const int N = 200500;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
int inv[N],fac[N],rev[N];
void init(int n){
	fac[0]=1;rev[n]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1;i<n;i++)inv[i]=(rev[i]*fac[i-1]%mod)%mod;
}
string t[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
signed main(){
	char c;
	int sum = 0;
	while((c=getchar())!='\n'){
		sum+=(c-'0');
	}
	vector<int>P;
	while(sum>9){
		P.pb(sum%10);
		sum/=10;
	}
	P.pb(sum);
	int l = P.size();
	for(int i=l-1;i>=0;i--){
		cout<<t[P[i]];
		if(i!=0)cout<<" ";
	}
	
	return 0;
}


