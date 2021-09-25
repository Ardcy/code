#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[200];
int b[200];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int ans1=0,ans3=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1&&b[i]!=1)ans1++;
		if(a[i]!=1&&b[i]==1)ans3++;
	}
	
	if(ans1==0)cout<<-1<<endl;
	else{
		int u = (ans3/ans1);
		u++;
		cout<<u<<endl;
	}
	
}
