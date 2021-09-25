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

int a[105000];
int b[105000];
int c[105000];
signed main(){
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i]>>c[i];
	
	
}


