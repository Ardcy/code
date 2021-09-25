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

int a1[100][100];
int b[10000];
signed main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		int j=1;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a1[i][j]=0;
		for(int i=1; i<=n; i++) {
			int cnt = 0;
			
			for(int x=1; x<=a; x++,j++) {
				
				if(j>m)j-=m;a1[i][j]=1;if(j>m)j-=m;
			}
		}
		int f=0;
		for(int i=1; i<=m; i++) {

			int cnt = 0;
			for(int j=1; j<=n; j++) {
				if(a1[j][i]) {
					cnt++;
				}
			}
		//	cout<<cnt<<endl;
			if(cnt!=b)f=1;

		}
		//cout<<f<<endl;
 		if(f)cout<<"NO"<<endl;else{
			cout<<"YES"<<endl;
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=m; j++) {
					cout<<a1[i][j];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}


