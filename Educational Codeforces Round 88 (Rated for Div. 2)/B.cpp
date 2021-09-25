#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};

int p[1050][1050];
signed main() {
	int t;
	cin>>t;
	char p1;
	while(t--) {
		int n,m,x,y;
		cin>>n>>m>>x>>y;
		getchar();
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				p1=getchar();
				if(p1=='*')p[i][j]=0;
				else p[i][j]=1,cnt++;
			}
			getchar();
		}
		for(int i=1;i<=n;i++)p[i][m+1]=0;
		//for(int i=1;i<=m;i++)p[n+1][m+1]=0;
		if(x*2<=y) {
			cout<<cnt*x<<endl;
		} else {
			int ans = 0;
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=m; j++) {
					if(p[i][j]==1&&p[i][j+1]==1)ans+=y,p[i][j+1]=0;
					else if(p[i][j]==1&&p[i][j+1]==0)ans+=x;
				}
				
			}
			cout<<ans<<endl;


		}
	}
	return 0;
}


