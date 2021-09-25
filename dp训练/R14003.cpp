#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000][3];
int b[105000][3];

signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i][0];
	}
	for(int i=1;i<=n;i++)cin>>b[i][1];
	for(int i=1;i<=n;i++){
		a[i][0]=max(a[i-1][1],a[i-1][2])+b[i][0];
		a[i][1]=max(a[i-1][0],a[i-1][2])+b[i][1];
		a[i][2]=max(a[i-1][1],a[i-1][0])+b[i][2];
	}
	cout<<max(max(a[n][0],a[n][1]),a[n][2]);
	return 0;
}
