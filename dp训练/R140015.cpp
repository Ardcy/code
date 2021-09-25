#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[600][600];
int b[600];
int c[600];
signed main(){
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		int ans = 0;
		for(int j=1;j<=m;j++){
			int cnt=0;
			if(a[i][j]==1)cnt=1;
			while(a[i][j]==a[i][j-1]&&a[i][j]==1)cnt++,j++;if(cnt)b[i]=max(b[i],cnt);
		}
	}
	int f1,f2;
	for(int i=1;i<=q;i++){
		cin>>f1>>f2;
		b[f1]=0;
		a[f1][f2]=1-a[f1][f2];
		for(int j=1;j<=m;j++){
			int cnt=0;
			if(a[f1][j]==1)cnt=1;
			while(a[f1][j]==a[f1][j-1]&&a[f1][j]==1)cnt++,j++;if(cnt)b[f1]=max(b[f1],cnt);
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			ans=max(ans,b[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
