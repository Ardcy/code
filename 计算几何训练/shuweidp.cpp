#include<bits/stdc++.h>
using namespace std;
int arr[20];
long long dp[20][10][2];
bool check(int x,int y){
	if(x==0||y==0)return true;
	if(x%y==0||y%x==0)return true;
	return false;
}
long long dfs(int pos,int pre,bool gzero,bool limit){
	if(pos==-1){
		return 1;
	}
	if(!limit&&~dp[pos][pre][gzero]){
		return dp[pos][pre][gzero];
	}
	int up = limit?arr[pos]:9;
	long long ans = 0;
	for(int i=0;i<=up;i++){
		if(check(i,pre)){
			ans += dfs(pos-1,i,gzero||i,i==up&&limit); 	
		}
	}
	if(!limit){
		dp[pos][pre][gzero] = ans;
	}
	return ans;
}
long long solve(long long x){
	int cnt = 0;
	while(x){
		arr[cnt++] = x%10;
		x/=10;
	}
	long long ans;
	ans = dfs(cnt-1,0,0,1);
	return ans;
}
signed main(){
	memset(dp,-1,sizeof(dp));
	int t;
	cin >> t;
	while(t--){
		long long l,r;
		cin >> l >> r;
		cout << solve(r) - solve(l-1) << endl;
	}
}