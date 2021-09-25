#include<bits/stdc++.h>
using namespace std;


int dp[10][20];


int arr[20];
int dfs(int pos,bool pre,bool limit){

	if(pos == -1){
		return 1;
	}

	if(!limit&&dp[pre][pos]!=-1){
		return dp[pre][pos];
	}
	int ans = 0;

	int up = limit?arr[pos]:9;
	for(int i=0;i<=up;i++){
		if(i==4)continue;
		if(pre==1&&i==2){
			
		}else {
			ans+=dfs(pos-1,i==6,i==up&&limit);
		}
	}
	if(!limit){
		dp[pre][pos] = ans;
	}
	return ans;
}


int solve(int x){
	int ans = 0;
	int cnt = 0;
	while(x){
		arr[cnt++] = x%10;
		x/=10;
	}
	ans = dfs(cnt-1,0,1);
	return ans;
}
signed main(){

	memset(dp,-1,sizeof(dp));
	
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0){
			break;
		}
		cout << solve(m) - solve(n-1) << endl;
	}
}