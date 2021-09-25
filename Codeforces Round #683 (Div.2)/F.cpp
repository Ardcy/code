#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N+5];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum = 0,minx = 1e9+7,maxx = 0;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			minx = min(arr[i],minx);
			maxx = max(arr[i],maxx);
			sum += arr[i];
		}
		int ans = 0;
		ans = max((sum+(n-2))/(n-1),maxx)*(n-1) - sum;
		cout<<ans<<endl;
	}
	
	return 0;
}
