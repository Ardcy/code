#include<bits/stdc++.h>
using namespace std;
int a[105000];
int main(){
	int n;
	cin>>n;
	int ans = 0;int cnt = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]>a[i-1])cnt++,ans=max(ans,cnt);
		if(i>1&&a[i]<=a[i-1])cnt=0;
	}
	cout<<ans<<endl;
}
