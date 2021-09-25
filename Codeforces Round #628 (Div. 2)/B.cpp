#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[200000];
int b[200000];
signed main(){
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		int cnt = n;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1])cnt--;
		}
		cout<<cnt<<endl;
	}
	
}
