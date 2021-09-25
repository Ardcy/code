#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int maxn = 2e5+5;
const int up = 1e5;
const ll inf = 0x7f7f7f7f;

struct node{
	int w,v;
}a[maxn];
ll dp[2][maxn];
signed main(){
	int t,n,m;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n+m;i++){
			int w,v;
			scanf("%lld%lld",&w,&v);
			w = i>n?-w:w;
			a[i] = {w,v};
		}
		n+=m;
		random_shuffle(a+1,a+1+n);
		int lim = 100000;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=2*up;j++){
				dp[i][j] = -1e18;
			}
		}
		dp[0][up] = 0;
		int op = 1;
		for(int i=1;i<=n;i++){
			for(int j= -lim;j<=lim;j++){
				dp[op][j+a[i].w + up]=max(dp[op^1][j+a[i].w+up],dp[op^1][j+up]+a[i].v);
			}
			op^=1;
		}
		printf("%lld\n",dp[op^1][up]);
	}

}