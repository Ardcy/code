#include<bits/stdc++.h>
using namespace std;
int arr[40];

long long dp[40][40][20][2];

long long dfs(int pos,int prenum,int pre,int limit,bool state){
	
	if(pos==-1){
		//cout << pre << " " << state << endl;
		return pre == 0 && state;
	}
	if(!limit&&~dp[pos][pre][prenum][state]){
		return dp[pos][pre][prenum][state];
	}
	int up = limit?arr[pos]:9;
	long long ans = 0;
	for(int i=0;i<=up;i++){
		ans += dfs(pos-1,i,(pre*10+i)%13,i==up&&limit,state||(prenum==1&&i==3));
	}
	if(!limit){
		dp[pos][pre][prenum][state] = ans;
	}
	return ans;
}

long long solve(long long x){
	int cnt = 0;
	while(x){
		arr[cnt++] = x%10;
		x/=10;
	}
	long long ans = dfs(cnt-1,0,0,1,0);
	return ans;
}
signed main(){
	memset(dp,-1,sizeof(dp));
	long long x;
	while(cin >> x){
		cout << solve(x) << endl;
	}
}