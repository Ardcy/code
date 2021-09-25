#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
int arr[N];
const int mod = 1e9+7;
int ans[N];
signed main(){
	int t;
	cin>>t;
	while(t--){
		
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			ans[i] = 0;
			cin>>arr[i];
		}
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(arr[i]==arr[1])
				cnt++;
		}
		if(cnt==n){
			cout<<0<<endl;
			continue;
		}
		for(int i=2;i<=n;i++){
			if(arr[i]!=arr[i-1]){
				ans[arr[i]] += 1; 	
			}	
		}
		int ans1 = 1e9+4;

		for(int i=1;i<=n;i++){
			if(ans[i])ans1 = min(ans[i]+(arr[n]!=i),ans1);
		}
		cout<<ans1<<endl;
	}
} 
