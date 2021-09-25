#include<bits/stdc++.h>
using namespace std;
long long arr[30];
long long dp[30][6000][30];

long long dfs(int pos,int pre,int k,bool limit){
	if(pos < 0){
		//cout << pre << endl;
		return pre == 0;
	}
	if(!limit&&dp[pos][pre+3000][k]>=0){
		return dp[pos][pre+3000][k];
	}
	int up = limit?arr[pos]:9;
	long long ans = 0;
	for(int i=0;i<=up;i++){
		ans += dfs(pos-1,pre+i*(pos-k),k,i==up&&limit);
	}
	if(!limit){
		dp[pos][pre+3000][k] = ans;
	}
	return ans;
}
long long solve(long long x){
	if(x==-1)return 0;
	int cnt = 0;
	while(x){
		arr[cnt++] = x%10;
		x/=10;
	}
	long long ans = 0;
	for(int i=0;i<cnt;i++){
		ans += dfs(cnt-1,0,i,1);
		//cout << ans << endl;
	}
	return ans-(cnt-1) ;
}
signed main(){
	memset(dp,-1,sizeof(dp));
	// long long x;
	// while(cin>>x)cout << solve(x) << endl;
	int n;
	cin >> n;
	long long l,r;
	while(cin >> l >> r){
		cout << (solve(r) - solve(l-1)) << endl;
	}
}