#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000];
int b[105000];
int n;
int gao(){
	int x=0,ret=0;
	for(int i=1;i<n;i++){
		x+=b[i];
		ret=max(ret,x);
		if(x<0)x=0;
	}
	return ret;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i+1];
		if(b[i]<0)b[i]*=-1;
		if(i%2==0)b[i]*=-1;
	}
	int r=gao();
	for(int i=1;i<n;i++)b[i]*=-1;
	r=max(r,gao());
	cout<<r<<endl;
	return 0;
} 
