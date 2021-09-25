#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N+5];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int ans = 0;
		for(int i=1;i<=n*k;i++){
			scanf("%lld",&arr[i]);
		}
		
		int p = (n+1)/2;
		int q = (p-1)*k+1;
		for(int now = q  ;now<= n*k;now += n - (p-1) ){
			//cout<<now<<endl;
			ans+=arr[now];
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}
