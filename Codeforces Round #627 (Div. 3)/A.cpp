#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[300000];
int b[300000];
signed main(){
	int n,m;
	int ans=0;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=1;int ans1=1;
		for(int i=1;i<=n;i++){
			if(a[i]%2==0)ans=0;
			if(a[i]%2==1)ans1=0;
		}
		if(ans||ans1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
		
}
