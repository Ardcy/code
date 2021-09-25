#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
const int mod = 1e9+7;
int dp[N];
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n = 0;
		cin >> n;
		dp[1] = 1;
		string pre,now;
		cin >> pre >> now;
		if(pre != now){
			dp[2] = 2;
		}else{
			dp[2] = 1;
		}

		for(int i=3;i<=n;i++){
			pre = now;
			cin >> now;
			if(pre != now){
				dp[i] = dp[i-1] + dp[i-2];
				dp[i] %= mod;
			}else{
				dp[i] = dp[i-1];
			}
		}
		cout << dp[n] << endl;
	}
}