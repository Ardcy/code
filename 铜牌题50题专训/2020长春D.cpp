#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[3005][3005];
int arr[4000];
int n;

int qp(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1)ans *= a, ans %= mod;
		a *= a, a %= mod;
		b >>= 1;
	} return ans;
}

int dfs(int pos , int num, bool limit) {
	if (pos == -1) {
		//cout << n << " " << num << endl;
		return qp(n, num);
	}
	if (!limit && ~dp[pos][num]) {
		return dp[pos][num];
	}
	int up = limit ? arr[pos] : 1;
	int ans = 0;
	for (int i = 0; i <= up; i++) {
		if (i == 0) {
			ans += dfs(pos - 1, num, i == up && limit);
		} else {
			ans += dfs(pos - 1, num + 1, i == up && limit);
		}
	}
	ans %= mod;
	if (!limit) {
		dp[pos][num] = ans;
	}
	return ans;
}


int solve(string s) {
	int cnt = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		arr[cnt++] = s[i] - '0';
	}

	int ans = 3;
	ans = dfs(cnt - 1, 0, 1);
	return ans;
}
signed main() {
	
	int p = arr[33992];
	memset(dp, -1, sizeof(dp));
	string s;

	cin >> s >> n;
	cout << solve(s) << endl;
}
