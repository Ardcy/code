#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000];
int b[105000];
int c[105000];
int d[105000];
signed main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)c[i]=c[i-1]+a[i];
	int m;
	cin>>m;
	int d,e,f;
	for(int i=1;i<=m;i++){
		cin>>d>>e>>f;
		if(d==1)cout<<(b[f]-b[e-1])<<endl;
		else cout<<(c[f]-c[e-1])<<endl;
	}
}
