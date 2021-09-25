#include<bits/stdc++.h>
using namespace std;
int a[600];
int b[600];
int main(){
	int n,k;
	cin>>n>>k;
	int ans =0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		if(a[i]+a[i+1]<k)ans += (k-a[i]-a[i+1]),a[i+1]=(k-a[i]);
		
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}
