#include<bits/stdc++.h>
using namespace std;



int n,m;
int arr[60][51];
int dp[51][51][51][51];
int dfs(int x,int y,int x1,int y1){
	if(x==x1&&y==y1)return 0;
	if(dp[x][y][x1][y1])return dp[x][y][x1][y1]; 
	if(x>n||y>m||x1>n||y1>m)return 0;
	int ans = 0;
	ans = max(dfs(x,y+1,x1+1,y1),dfs(x,y+1,x1,y1+1));
	ans = max(ans,dfs(x+1,y,x1+1,y1));
	if(!(x+1==x1&&x==y1+1)){
		ans = max(ans,dfs(x+1,y,x1,y1+1));
	}
	dp[x][y][x1][y1] = ans+ arr[x][y] + arr[x1][y1];
	return ans + arr[x][y] + arr[x1][y1];
}
signed main(){
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> arr[i][j];
		}
	}
	cout << dfs(1,2,2,1) + arr[1][1] + arr[n][m]<< endl;
}