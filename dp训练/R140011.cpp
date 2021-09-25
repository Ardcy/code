#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin>>n;
	int a,cnt=0,e=1000000000000,ans=0,f=-100000000000,ans1=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a>0)ans+=a;
		if(a%2!=0&&a>0)cnt++;
		if(a>0&&a%2==0)ans1+=a;
		if(a>0&&a%2!=0)e=min(e,a);
		if(a<0&&a%2!=0)f=max(a,f);
	}
	if(cnt==0)cout<<f+ans1<<endl;
	else if(cnt%2==1)cout<<ans<<endl;
	else if(f!=-100000000000)cout<<max(ans-e,ans+f)<<endl;
	else cout<<ans-e<<endl;
	return 0;
}
