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
struct node{
	int x,y;
}e[N];
int a[N];
bool cmp(node a1,node a2){
	return a1.x<a2.x;
}
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>e[i].x;
	for(int i=1;i<=n;i++)a[i]=e[i].x,e[i].y=i;
	sort(e+1,e+n+1,cmp);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(e[i].x==a[i])cnt++;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++){
		if(e[i].x==a[i])cout<<a[i]<<(i!=n?" ":"\n");
	}
	return 0;
}


