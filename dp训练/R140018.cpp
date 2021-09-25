#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200000];
signed main(){
	int n,l=0,r=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l;
		a[++l]=i;
		r=max(r,i-min(max(a[l-2],a[l+1]),max(a[l-1],a[l+2])));
	}
	cout<<r<<endl;
	return 0;
}
