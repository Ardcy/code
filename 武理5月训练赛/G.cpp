#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 1e9+7;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};
int inv(int p) {
	return qp(p,mod-2);
}
int a[2][400][400];
int dx[] = {1,0,-1,0,0};
int dy[] = {0,1,0,-1,0};
signed main() {

	int n,m,k;
	cin>>n>>m>>k;
	a[0][1][1]=1;
	int b = 0;
	while(k--) {
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)a[1-b][i][j]=0;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i==1||i==n) {
					if(j==1||j==n) {
						for(int g=0; g<5; g++) {
							a[1-b][i+dx[g]][j+dy[g]]+=a[b][i][j]*inv(3);
							a[1-b][i+dx[g]][j+dy[g]]%=mod;
						}
					} else {
						for(int g=0; g<5; g++) {
							a[1-b][i+dx[g]][j+dy[g]]+=a[b][i][j]*inv(4);
							a[1-b][i+dx[g]][j+dy[g]]%=mod;
						}
					}

				} else {
					if(j==1||j==n) {
						for(int g=0; g<5; g++) {
							a[1-b][i+dx[g]][j+dy[g]]+=a[b][i][j]*inv(4);
							a[1-b][i+dx[g]][j+dy[g]]%=mod;
						}

					} else {
						for(int g=0; g<5; g++) {
							a[1-b][i+dx[g]][j+dy[g]]+=a[b][i][j]*inv(5);
							a[1-b][i+dx[g]][j+dy[g]]%=mod;
						}
					}
				}
			}
		}
		b=1-b;
	}
	cout<<a[b][1][1]<<endl;
	return 0;
}


