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
		int f=1;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(a[i]==a[j]){
					f=0;
				}
			}		
		}
		if(f==0)cout<<"YES"<<endl;else cout<<"NO"<<endl;
		
	}
	return 0;
		
}
