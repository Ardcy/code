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
int jie[205000];
int a[205000];
int pre1[205000],pre2[205000],h[205000],h1[205000];
signed main(){
	int n;
	cin>>n;
	jie[0]=0;
	for(int i=1;i<=200000;i++)jie[i]=jie[i-1]+i,jie[i]%=mod;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)pre1[i]=pre1[i-1]+jie[i]*a[i],pre1[i]%=mod;
	for(int i=n;i>=1;i--)h[i]=h[i+1]+(n+1-i)*a[i],h[i]%=mod;
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans+=i*a[i]*h[i];
		ans%=mod;
	}
	cout<<ans<<endl;
	
	return 0;
}


