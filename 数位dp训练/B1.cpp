#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int cnt;
long long dp[30][1100][12];
int arr[30];
int dp1[3000][12];
int get_state(int p,int x){
	int y = x;
	if(dp1[p][x]){
		return dp1[p][x];
	}
	x = (1<<x);
	if(p<x){
		dp1[p][y] = p+x;
		return p+x;
	}
	else if(p&x){
		dp1[p][y] = p;
		return p;
	}else{
		int p1 = p%x;
		int pp = p;
		p -= p1;
		for(int i=0;i<13;i++){
			if((long long)(1<<i)&p){
				p-=(1<<i);
				break;
			}
		}
		dp1[pp][y] = p+p1+x;
		return p+p1+x;
	}
}
int dp2[2000][12];
bool cal(int p,int k){
	if(dp2[p][k]){
		return dp2[p][k] == 2;
	}
	int cnt  = 0;
	for(int i=0;(1<<i)<=p;i++){
		if((1<<i)&p)cnt++;
	}
	dp2[p][k] = ((cnt==k)+1);
	return cnt==k;
}
long long qp(int a,int b){
	long long ans = 1;
	for(int i=1;i<=b;i++){
		ans *= a;
	}
	return ans;
}
long long int pcnt = 0;
long long int pcnt1 = 0;
long long dfs(int pos,int now,int k,bool limit){
	pcnt++;
	if(pos==-1){
		return cal(now,k);
	}
	if(~dp[pos][now][k]){
		pcnt1++;
	}
	if(!limit&&~dp[pos][now][k]){
		return dp[pos][now][k];
	}
	int up = limit?arr[pos]:9;
	long long int ans = 0;
	for(int i=0;i<=up;i++){	
		if((now==0&&i==0)){
			ans += dfs(pos-1,0,k,0);
		}
		else{
			if(__builtin_popcount(get_state(now,i))<= k||limit)
				ans += dfs(pos-1,now==0?(1<<i):get_state(now,i),k,(i==up)&&limit);
		}
	}
	if(!limit){
		dp[pos][now][k] = ans;
	}
	return ans;
}
long long get_ans(long long x,int k){
	cnt = 0;
	while(x){
		arr[cnt++] = x%10;
		x/=10;
	}
	long long ans = dfs(cnt-1,0,k,1);
	return ans;
}
int brr[30];
int crr[30];
signed main(){
	memset(dp,-1,sizeof(dp));
	int kcase = 1;
	int t;
	cin >>t;
	while(t--){
		long long l,r;
		int k;
		scanf("%lld%lld%d",&l,&r,&k);
		printf("Case #%d: %lld\n",kcase++,get_ans(r,k) - get_ans(l-1,k));
	}
}