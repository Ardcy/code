#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int arr[30];
long long int dp[30][40];
long long dfs(int pos,bool pre,bool limit){
	if(pos==-1){
		return 0;
	}
	if(!limit&&dp[pre][pos]>=0){
		return dp[pre][pos];
	}
	int up = limit?arr[pos]:9;
	long long ans = 0;
	for(int i=0;i<=up;i++){
		if(i==9&&pre){
			if(!limit){
				long long b = 1;
				long long p = pos;long long y = 10;
				while(p){
					if(p&1)b*=y;
					y*=y;
					p>>=1;
				}
				ans += b;	
			}else{
				long long base = 1;
				long long ans1=  0;
				for(int ii=0;ii<=pos-1;ii++){
					ans1 += base * arr[ii];
					base*=10;
				}
				ans += ans1 + 1;
			}
			
		}else{
			ans += dfs(pos-1,i==4,i==up&&limit);
		}
	}
	if(!limit)dp[pre][pos] = ans;
	return ans;
}
long long solve(long long x){
	cnt = 0;
	while(x){
		arr[cnt++] = x%10;
		x/=10; 
	}
	return dfs(cnt-1,0,1);
}
signed main(){
	memset(dp,-1,sizeof(dp));
	int t;
	cin >> t;
	while(t--){
		long long int n;
		cin >> n;
		cout << solve(n) << endl;
	}
}