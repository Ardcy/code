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

int a[205000];
int pre1[205000],pre2[205000],h[205000],h1[205000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)pre1[i]=pre1[i-1]+a[i],pre2[i]=pre2[i-1]+pre1[i],pre1[i]%=mod,pre2[i]%=mod;
	for(int i=n;i>=1;i--)h[i]=h[i+1]+a[i],h1[i]=h1[i+1]+h[i],h[i]%=mod,h1[i]%=mod;
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans+=pre2[i]*h1[i];
		ans%=mod;
	}
	cout<<ans<<endl;
	
	return 0;
}


