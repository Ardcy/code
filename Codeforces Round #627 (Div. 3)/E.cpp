#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[300000];
int b[3000][3000]={0};
int c[3000][3000];
signed main(){
	int n,h,l,r;
	cin>>n>>h>>l>>r;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if((c[i-1][1]+a[i]-1+h)%h>=l&&(c[i-1][1]+a[i]-1+h)%h<=r)b[i][1]=b[i-1][1]+1;
		else b[i][1]=b[i-1][1];
		if((c[i-1][i]+a[i]+h)%h>=l&&(c[i-1][i]+a[i]+h)%h<=r)b[i][i+1]=b[i-1][i]+1;
		else b[i][i+1]=b[i-1][i];
		for(int j=2;j<=i;j++){
			if((c[i-1][j-1]+a[i]+h)%h>=l&&(c[i-1][j-1]+a[i]+h)%h<=r)b[i][j]=max(b[i-1][j],b[i-1][j-1])+1;
			else b[i][j]=max(b[i-1][j],b[i-1][j-1]);
		}
		c[i][1]=(c[i-1][1]+a[i]-1+h)%h;
		for(int j=2;j<=i+1;j++){
			c[i][j]=(c[i-1][j-1]+a[i]+h)%h;
		}
//		for(int j=1;j<=i+1;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//		for(int j=1;j<=i+1;j++){
//			cout<<c[i][j]<<" ";
//		}
//		cout<<endl;
	}
	int ans=0;
	for(int i=1;i<=n+1;i++){
		ans=max(ans,b[n][i]);
	}
	cout<<ans<<endl;
}
