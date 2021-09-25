#include<bits/stdc++.h>
#define de(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[60000][6];
int b[6];
int ans[60000][6];
signed main(){
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int ans1=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ans[j][i]=max(ans[j-1][i],ans[j][i-1])+a[j][i];
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i][m]<<endl;
	return 0;
}
