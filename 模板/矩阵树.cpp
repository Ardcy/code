#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;
int n,m[18],vx[18][140],vy[18][140],v[18];
ll a[18][18],ans;
inline ll pow(ll x,ll y){
	ll ans = 1;
	while(y){
		if(y&1)ans = ans*x %mod;
		x = x*x%mod;y>>=1;
	}return ans;
}
void dfs(int x,int flag){
	if(x==n){
		memset(a,0,sizeof(a));
		int i,j,k;
		ll now = 1,t;
		for(i=2;i<=n;i++){
			for(j=i;j<=n;j++){
				if(a[j][i])break;
				if(j>n)break;
				if(j!=i){
					flag = -flag;
					for(k = i;k<=n;k++){
						swap(a[i][k],a[j][k]);
					}
				}
				now = now*a[i][i]%mod,t = pow(a[i][i],mod-2);
			}
		}
	}
}