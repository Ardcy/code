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
char d[2000][1100];
int vis[1100][1100];
int cnt = 1;
int n,m;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
void dfs(int i,int j,int p) {
	vis[i][j]=p;
	for(int a=0; a<4; a++) {
		if(i+dx[a]>=1&&i+dx[a]<=n) {
			if(j+dy[a]>=1&&j+dy[a]<=m) {
				if(!vis[i+dx[a]][j+dy[a]] && d[i+dx[a]][j+dy[a]]=='#')
					dfs(i+dx[a],j+dy[a],p);
			}
		}
	}
}
int d1[1020],d2[1020];
signed main() {
	cin>>n>>m;
	getchar();
	char u;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++)d[i][j]=getchar();
		getchar();
	}
	int h = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(d[i][j]=='#') {

				h++;
			}
		}
	}
	if(!h) {
		cout<<0<<endl;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(!vis[i][j]&&d[i][j]=='#') {
				dfs(i,j,cnt);
				cnt++;
			}
		}
	}
	int f1 = 1;
	for(int i=1; i<=n; i++) {
		int cnt1 = 0;
		for(int j=1; j<=m; j++) {
			if(d[i][j]=='#')cnt1++;
		}
		d1[i]=cnt1;
	}
	for(int i=1; i<=m; i++) {
		int cnt1 = 0;
		for(int j=1; j<=n; j++) {
			if(d[j][i]=='#')cnt1++;
		}
		d2[i]=cnt1;
	}
	for(int i=1; i<=n; i++) {
		int ff = 0;
		if(d1[i]==0) {
			ff = 0;
			for(int j=1; j<=m; j++) {
				if(d2[j]==0)ff=1;
			}
			if(!ff)f1=0;
		}
	}
	for(int i=1; i<=m; i++) {
		int ff = 0;
		if(d2[i]==0) {
			ff = 0;
			for(int j=1; j<=n; j++) {
				if(d1[j]==0)ff=1;
			}
			if(!ff)f1=0;
		}
	}
	for(int i=1; i<=n; i++) {
		int cnt1 = 0;
		int f2 = 0;
		int f3 = 0;
		for(int j=1; j<=m; j++) {
			if(d[i][j]=='#'&&f3==0)f2=1;
			else if(d[i][j]=='.'&&f2==1)f3=1,f2=0;
			else if(d[i][j]=='.'&&f2==0);
			else if(d[i][j]=='#'&&f3==1){f2=1;break;}
		}	
		if((f2==1&&f3==1))f1=0;
	}
	for(int i=1; i<=m; i++) {
		int cnt1 = 0;
		int f2 = 0;
		int f3 = 0;
		for(int j=1; j<=n; j++) {
			if(d[j][i]=='#'&&f3==0)f2=1;
			else if(d[j][i]=='.'&&f2==1)f3=1,f2=0;
			else if(d[j][i]=='.'&&f2==0);
			else if(d[j][i]=='#'&&f3==1){f2=1;break;}
		}
		if((f2==1&&f3==1))f1=0;
	}
	if(f1==0) {
		cout<<-1<<endl;
	} else {
		cout<<cnt-1<<endl;
	}
	return 0;
}


