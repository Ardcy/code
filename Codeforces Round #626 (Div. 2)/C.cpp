#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[300000];
int b[300000];
signed main(){
	int n,m;
	cin>>n>>m;
	if(n>m+1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans = 1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans*=abs(a[j]-a[i]);
			ans%=m;
			if(ans==0){
				cout<<0<<endl;
				return 0;
			}
		}
	}
	cout<<ans<<endl;
		
}
