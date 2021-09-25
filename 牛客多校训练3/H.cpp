#include<bits/stdc++.h>
using namespace std;


int dp[600][600];
vector<int>P[600];
int arr[600][600];

signed main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int k;
			cin >> arr[i][j];
			k = arr[i][j];
			if(k==1)
			P[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		if(arr[i][(i+1==n+1)?1:i+1]){
			dp[i][1] = 1;
		}
	}

	for(int length = 2;length <= n ; length++){
		for(int i=1;i<=n;i++){
			int p = max(dp[i][length-1],dp[i+1][length-1]);
			int ans1 = 0;
			p = max(p,dp[i][length - 2] + dp[i+length-1>n?i+length-1-n:i+length-1][1]); 
			p = max(p,dp[i][1] +dp[i+2][length - 2]);
			p = max(p,arr[i][i+length>n?i+length-n:i+length] + dp[i+1][length - 2]);
			ans1 = p;
			for(int j=i+1;j<i+length;j++){
				//cout << " --- " << endl;
				ans1 = max(ans1,dp[i+1>n?i+1-n:i+1][max(j-i-2,0)] + arr[i][j>n?j-n:j] + dp[j+1>n?j+1-n:j+1][length-(j-i)-1]);
			}
			dp[i][length] = ans1;
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans,dp[i][n-1]);
	}
	cout << ans << endl;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout << dp[i][j] << " ";
	// 	}cout << endl;
	// }

	//cout << dp[1][n] <<endl;
}