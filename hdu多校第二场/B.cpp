#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 1e9+7;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
#define ll long long

int T,d;
ll l,r;
int y = 0;
int cnt[11];
ll dp[11][22],C[22][22];
int a[22];
ll dfs(int pos,int limit,int lead){
	if(pos==-1){
		int mx = 0,num = 0;
		for(int i=0;i<=9;i++)if(cnt[i]>cnt[mx])mx=i;
		for(int i=0;i<=9;i++)if(cnt[i]==cnt[mx])num++;
		return mx==d&&num==1;
	}
	if(!limit&&!lead){
		ll ans = 0;
		int mx = cnt[d];
		for(int i=0;i<=9;i++)if(i!=d)mx=max(mx,cnt[i]+1);
		for(int num=mx;num<=cnt[d]+pos+1;num++){
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			for(int i=1;i<=10;i++){
				if(i==d+1){
					for(int j=0;j<=20;j++)dp[i][j]=dp[i-1][j];
					continue;
				}
				for(int j=0;j<=cnt[d]+pos+1-num;j++){
					for(int k=0;k<=num-cnt[i-1]-1&&j-k>=0;k++){
						dp[i][j]+=dp[i-1][j-k]*C[pos+1-j+k][k];
					}
				}
			}
			ans+=dp[10][cnt[d]+pos+1-num];
			
//			cout<<"----------"<<"\n"<<(y++)<<endl; 
//			cout<<dp[10][cnt[d]+pos+1-num];
		}
		return ans;
	}
	int up=limit?a[pos]:9;
	ll ans = 0;
	for(int i=0;i<=up;i++){
		if(!lead||i!=0)cnt[i]++;
		ans+=dfs(pos-1,limit&&i==a[pos],lead&&i==0);
		
		if(!lead||i!=0)cnt[i]--;
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

