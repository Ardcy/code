#include<bits/stdc++.h>
using namespace std;
char arr[3000][3000];


long long Ans[3000][3000];
const int inf = 0x3f3f3f3f;


int dx[] = {0,1,0,-1,0};
int dy[] = {0,0,1,0,-1};
int n,m;

void dfs(int x,int y){
	for(int i=1;i<=4;i++){
		if(x + dx[i] <=n && x + dx[i] >=1 && y + dy[i] >=1 && y + dy[i] <= m)
		if(arr[x+dx[i]][y+dy[i]] == '*'&&Ans[x+dx[i]][y+dy[i]] > Ans[x][y] + 1){
			Ans[x+dx[i]][y+dy[i]] = Ans[x][y] + 1;
			dfs(x+dx[i],y+dy[i]);
		}
	}
}
signed main(){
	
	cin >> n >> m;
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j] = getchar();
		}getchar();
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		Ans[i][j] = inf;
	Ans[1][1] = 0;
	dfs(1,1);
	cout << Ans[n][m] << endl;
}  