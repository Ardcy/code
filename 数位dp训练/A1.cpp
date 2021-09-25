#include<bits/stdc++.h>
#include<time.h>
using namespace std;

int arr[30];
long long dp[30][60][2530];
int cnt;
//unordered_map<int,int>mp;
int mp[2530];
long long dfs(int pos,int lcm,int num,bool limit){
	//cout << " ------ " << endl;
	if(pos == -1){
		//cout << num <<" "<< lcm << endl;
		return 1LL*(num%lcm ==0);
	}
	if(!limit&&dp[pos][mp[lcm]][num]){
		return dp[pos][mp[lcm]][num];
	}
	int up = limit?arr[pos]:9;
	long long int ans = 0;
	for(int i=0;i<=up;i++){
		ans += dfs(pos-1,lcm*(i?i:1)/__gcd(lcm,(i?i:1)),(num*10+i)%2520,i==up&&limit);
	}
	if(!limit)dp[pos][mp[lcm]][num] = ans;
	return ans;
}

long long get_ans(long long x){
	//memset(dp,0,sizeof(dp));
	cnt = 0;
	while(x){
		arr[cnt++] = x%10;
		x/=10;
	}
	long long ans = dfs(cnt-1,1,0,1);
	return ans;
}
signed main(){
	clock_t st,ed;
	st = clock();
	// freopen("in.txt","r",stdin);
	int cnt = 0;
	for(int i=1;i<=2520;i++){
		if(2520%i==0){
			mp[i] = cnt++;

		}
	}
	//cout << cnt << endl;
	//
	int t;
	cin >> t;
	while(t--){
		long long l,r;
		cin >> l >> r;
		// cout << get_ans(r) - get_ans(l-1)<<endl;
		printf("%lld\n",get_ans(r) - get_ans(l-1));
	}
	ed = clock();
	cout << (double)(ed-st)/CLOCKS_PER_SEC << endl;
}