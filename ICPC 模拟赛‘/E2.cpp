#include <iostream>
#define int long long
using namespace std;
int a[150];
int dp[150][150];
int n;
#define int long long
signed main() {

	while(cin >> n) {
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			for(int j = 1; j <= n; j++) {
				dp[i][j] = 0x3f3f3f3f;
			}
			
			dp[i][i+1] = 0;
			dp[i][i-1] = 0;
		}
		int ans = 0;
		for(int len = 3; len <= n; len++) {
			for(int l = 1; l <= n - len + 1;l ++) {
				int r = l + len - 1;
				if(len == 3) {
					dp[l][r] = (a[l] + a[l + 1] + a[r]) * (a[l] + a[l + 1] + a[r]);
					continue;
				} 
				for(int k = l + 1; k <= r - 1; k ++) {
					dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + (a[l] + a[k] + a[r]) * (a[l] + a[k] + a[r]));
				}
			} 
			
		}
		cout << dp[1][n] << endl;
		
	} 
	return 0;
}
