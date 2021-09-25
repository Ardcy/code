#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000];
int l[105000];
int r[105000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		l[i]=(a[i]>a[i-1]?l[i-1]+1:1);
	}
	for(int i=n;i>=1;i--)
		r[i]=(a[i]<a[i+1]?r[i+1]+1:1);
	int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,max(l[i],r[i]));
	}
	for(int i=2;i<n;i++){
		if(a[i-1]<a[i+1])res=max(res,l[i-1]+r[i+1]);
	}
	cout<<res<<endl;
	cout<<cnt<<endl;
	return 0;
}
