#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[4000];
int c[4000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	int ans=10000000000000000;
	int f=0;
	int f1=0;
	for(int j=2;j<=n-1;j++){
		f=0;
		int ans1=1000000000000;
		int ans2=1000000000000;
		for(int i=1;i<j;i++){
			if(s[i]<s[j]&&c[i]<ans1)ans1=c[i];
		}
		if(ans1==1000000000000)f=1;
		for(int k=j+1;k<=n;k++){
			if(s[k]>s[j]&&c[k]<ans2)ans2=c[k];
		}
		if(ans2==1000000000000)f=1;
		ans=min(ans,ans1+ans2+c[j]);
		if(!f)f1=1;
	}
	if(f1)cout<<ans<<endl;else cout<<-1<<endl;
	
	
	return 0;
}
