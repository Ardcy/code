#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
int T,d;
ll l,r;
int cnt[11];
ll dp[11][22],C[22][22];
int a[22]; 


ll dfs(int pos,int limit,int lead){
	// 如果处理到最后一位 ,判断d是否是出现最多次的一位 
	if(pos==-1){
		int mx = 0,num = 0;
		for(int i=0;i<=9;i++)if(cnt[i]>cnt[mx])mx=i;
		for(int i=0;i<=9;i++)if(cnt[i]==cnt[mx])num++;
		return mx==d&&num==1;
	}
	
	// 如果无限制且非前导0 
	if(!limit&&!lead){
		ll ans = 0;
		int mx = cnt[d];
		// 之前已经出现过的需要规划的数字个数
		for(int i=0;i<=9;i++)if(i!=d)mx=max(mx,cnt[i]+1);
		// mx表示最小的 d要出现的次数
		// 应当比其余数字均大1
		// 得到的最大的数字个数加1的值 
		// 此时已经无限制，且无前导0，且已知各数字已经出现过的次数 
		//目的是求得 使得d出现最多次的可能
		// pos+1 表示还空余几个位置
		// cnt[d] 表示 还d已经出现过多少次
		// num 表示该结果中 d可能出现的次数 
		// 枚举数码d可能出现的次数 
		for(int num = mx;num<=cnt[d]+pos+1;num++){
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			// i表示数
			for(int i=1;i<=10;i++){
				// 如果i代表了 目的数字 
				if(i==d+1){
					for(int j=0;j<=20;j++){
						dp[i][j]=dp[i-1][j];
						
					}continue; 
				}
				// 则跳过目标数字  
                // j的范围对应num的范围
				// 降低一定复杂度			
				// 重点 ----  dp
				// dp[i][j] 表示前i位除了指定的那一位外已经在剩余的位置安放了j个数
				// 重点 前i位 看成了整体 
				// cnt[d]+pos+1-num 枚举后的剩余位置个数
				// num - cnt[i-1] - 1 表示 数字 i 可能出现的最大次数  
				// j-k > 0 保证了 数字i的 新加数量不会超过剩余位置个数 
				// dp[i][j]的计算方式
				// 剩余了  cnt[d]+pos+1-num 个位置的情况了
				// 我已知了 前三位数字放到 10个位置中的所有情况
				// 前x+1位 放到 10个位置中的情况数
				// pos+1-j+k 表示 空位 - 空位中的已经占有的位置 + 数字i新增的次数
				// 等同于 实际空位 实际空位中选择  k 个位置 放入 i的方法数 
				for(int j=0;j<=cnt[d]+pos+1-num;j++){
					for(int k=0;k<=num-cnt[i-1]-1&&j-k>=0;k++){
						dp[i][j]+=dp[i-1][j-k]*C[pos+1-j+k][k];
					}	
				}
			}
			//每次枚举之后添加一个答案 
			ans += dp[10][cnt[d]+pos+1-num];
			// dp[10][cnt[d]+pos+1-num] 表示 10位全部放后的 所有位置都放好数字 的可能性 
					
		} 
		return ans;
	}
	int up = limit?a[pos]:9;
	ll ans = 0;
	
	for(int i=0;i<=up;i++){
		
		// 复杂度估计：
		// 不加优化的情况下复杂度为 9的18次。
		// 加优化后复杂度为 O(进制)*O（数字最大位数）*O（dp）
		 
		if(!lead||i!=0)cnt[i]++;
		// 等价于 前导0且i=0才不变，其余情况均改变
		// 前导0终将变成非前导0
		// 如果非前导0 或者 该位选择的数字不是0 那么cnt[i]++; 
		// 举例说明
		// 如果1235
		// 枚举0的时候，如果是前导0，lead=true,则当前位也按照前导0处理
		// 如果是1023 枚举第二位的0，lead=false,那么这一位应当被计数
		ans+=dfs(pos-1,limit&&i==a[pos],lead&&i==0);
		// 如果limit是true
		// 且当前选择位数字是最大数字
		// 则延续该limit
		// 如果当前无限制，则后一位必定也无限制
		// 前导0，下一位是前导0的条件必须是 上一位是前导0且上一位数字是0；
		if(!lead||i!=0)cnt[i]--;
		
		// 状态还原 
	}
	return ans;
}
ll solve(ll x){
	int len = 0;
	while(x){
		a[len++]=x%10;x/=10;
	}
	return dfs(len-1,true,true);
}
int main(){
	C[0][0]=1;
	for(int i=1;i<=20;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%d",&l,&r,&d);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}
