#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[2000];
int b[2000];
signed main(){
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		for(int i=1;i<n;i++)cout<<a[i]<<" ";
		cout<<a[n]<<endl;
		for(int i=1;i<n;i++)cout<<b[i]<<" ";
		cout<<b[n]<<endl;
	}
	
}
