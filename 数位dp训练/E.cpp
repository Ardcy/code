#include<iostream>
#include<string.h>
using namespace std;

int arr[50];

long long int dp[50][50][50];

long long dfs(int pos,int num1,int num0,bool limit){
	
	//cout << "-----" <<endl;
	if(pos<0){
		//cout << num1 << " " << num0 << endl;
		return num1 <= num0;
	}
	if(!limit&&dp[pos][num1][num0]>=0){
		return dp[pos][num1][num0];
	}
	int up = limit?arr[pos]:1;
	long long ans = 0;
	for(int i=0;i<=up;i++){
		if(num1==0&&num0==0){
			ans += dfs(pos-1,i==1,0,i==up&&limit);
		}else{
			ans += dfs(pos-1,num1 +(i==1),num0 + (i==0),i==up&&limit);
		}
	}
	if(!limit){
		dp[pos][num1][num0] = ans;
	}
	return ans;
}
long long solve(long long x){
	int cnt = 0;
	while(x){
		if(x&1)arr[cnt++] = 1;
		else arr[cnt++] = 0;
		x>>=1;
	}
	return dfs(cnt-1,0,0,1);
}

signed main(){

	memset(dp,-1,sizeof(dp));
	// long long x;
	// while(cin>>x){
	// 	cout<< solve(x) << endl;
	// }

	long long l,r;
	while(cin >> l >> r)
		cout << (solve(r) - solve(l-1)) << endl;	
}