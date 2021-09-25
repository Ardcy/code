#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100];
int b[100];
int ans=0;
signed main(){
	int v1,v2;
	int t,d;
	cin>>v1>>v2>>t>>d;
	a[1]=v1;
	for(int i=2;i<=t;i++)a[i]=a[i-1]+d;
	b[t]=v2;
	for(int i=t-1;i>=1;i--)b[i]=b[i+1]+d;
	for(int i=1;i<=t;i++){
		if(a[i]<b[i])ans+=a[i];
		else ans+=b[i];
	}
	cout<<ans<<endl;
	return 0;
}
