#include<bits/stdc++.h>
using namespace std;
char arr[3000][3000];
long long dp[3000][3000];
signed main(){
	int n,m;
	cin >> n >> m;
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j] = getchar();
		}getchar();
	}
	for(int i=1;i<=n;i++)dp[i][0] = 4000;
	for(int i=1;i<=m;i++)dp[0][i] = 4000;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&j==1){
				dp[i][j] = 0;continue;
			}
			if(arr[i][j] == '#'){
				dp[i][j] = 10000;
				continue;
			}
			if(arr[i][j] == '*'){
				dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + 1;
			}
		}
	}
	cout << dp[n][m] << endl;
}