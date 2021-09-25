#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[105000];
int h[105000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>h[i];
	x[n+1]=INT_MAX;
	int ans = 0;
	int last = INT_MIN;
	for(int i=1;i<=n;i++){
		if(x[i]-h[i]>last)last=x[i],ans++;
		else if(x[i]+h[i]<x[i+1])last=x[i]+h[i],ans++;
		else last=x[i];
	}
	cout<<ans<<endl;
	return 0;
}
