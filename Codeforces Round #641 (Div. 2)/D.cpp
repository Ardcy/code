#include<bits/stdc++.h>
using namespace std;
int a[105000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		int b = 0;
		for(int i=1;i<=n;i++)if(a[i]==k)b=1;
		if(!b){cout<<"no"<<endl;continue;}a[n+1]=0;a[n+2]=0;
		for(int i=1;i<=n;i++)if(a[i]>=k&&(max(a[i+1],a[i+2])>=k))b=0;
		if(n==1&&a[1]>=k)b=0;
		if(b){cout<<"no"<<endl;}else cout<<"yes"<<endl;
	}
	
	
}
