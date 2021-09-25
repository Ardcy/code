#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000];
int b[1000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=a[i];
	int ans1=0;
	for(int i=n;i>=2;i--){
		int ans = 1e9,ind = 0;
		
		
		for(int j=1;j<i;j++){
			if(ans>b[j]+b[j+1])ans=b[j]+b[j+1],ind=j;
		}
		cout<<ans<<endl;
		ans1+=ans;
		for(int j=1;j<i;j++){
			if(j<ind)b[i]=b[i];
			if(j==ind)b[i]=b[i]+b[i+1];
			if(j>ind)b[i]=b[i+1];
		}
		
	} 
	cout<<ans1<<endl;
}
