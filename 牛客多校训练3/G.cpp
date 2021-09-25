#include<bits/stdc++.h>
using namespace std;
#define double long double
const int N =1000;
int arr[N];
double dp[200][200];

double solve(int x){
	dp[0][0] = 1;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x;j++){
			dp[i][j] = 0.0;
		}
	}
	for(int i=1;i<=x;i++){
		dp[i][0] = dp[i-1][0] * ((100-arr[i])*1.0/100) ;
		for(int j=1;j<=i;j++){
			dp[i][j] = dp[i-1][j]*((100-arr[i])*1.0/100) + dp[i-1][j-1]*((arr[i])*1.0/100) ;
		}
	}
	// for(int i=0;i<=x;i++){
	// 	for(int j=0;j<=x;j++){
	// 		cout << dp[i][j] << " ";
	// 	}cout << endl;
	// }
	double ans = 0.0;
	for(int i=1;i<=x;i++){
		ans += dp[x][i] * pow(i,i*1.0/x);
	}
	//cout << ans << endl;
	return ans;
}
signed main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr+1,arr+n+1,greater<int>());
	double ans = 0.0;
	// solve(1);
	for(int i=1;i<=n;i++){
		ans = max(ans,solve(i));
	}
	// cout << ans << endl;
	printf("%.10Lf\n",ans);
}