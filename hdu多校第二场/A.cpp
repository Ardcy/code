#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<sstream>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#include<map>
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define per(i,n,x) for(int i=n;i>=x;i--)
#define sz(a) int(a.size())
#define rson mid+1,r,p<<1|1
#define pii pair<int,int>
#define lson l,mid,p<<1
#define ll long long
#define pb push_back
#define mp make_pair
#define se second
#define fi first
using namespace std;
const double eps=1e-8;
const int mod=1e9+7;
const int N=1e5+10;
const int inf=1e9;
int T,d;
ll l,r;
int cnt[11];
ll dp[11][22],C[22][22];
int a[22];
ll dfs(int pos,int limit,int lead){
    if(pos==-1){
        int mx=0,num=0;
        rep(i,0,9)  if(cnt[i]>cnt[mx]) mx=i;
        rep(i,0,9) if(cnt[i]==cnt[mx]) num++;
        return mx==d&&num==1;
    }
    if(!limit&&!lead){
        ll ans=0;
        int mx=cnt[d];
        rep(i,0,9) if(i!=d) mx=max(mx,cnt[i]+1);
        for(int num=mx;num<=cnt[d]+pos+1;num++){
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            rep(i,1,10){
                if(i==d+1){
                    for(int j=0;j<=20;j++) dp[i][j]=dp[i-1][j];
                    continue;
                }
                for(int j=0;j<=cnt[d]+pos+1-num;j++){
                    for(int k=0;k<=num-cnt[i-1]-1&&j-k>=0;k++){
                        dp[i][j]+=dp[i-1][j-k]*C[pos+1-j+k][k];
                    }
                }
            }
            ans+=dp[10][cnt[d]+pos+1-num];
        }
        return ans;
    }
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++){
        if(!lead||i!=0) cnt[i]++;
        ans+=dfs(pos-1,limit&&i==a[pos],lead&&i==0);
        if(!lead||i!=0) cnt[i]--;
    }
    return ans;
}
ll solve(ll x){
    int len=0;
    while(x){
        a[len++]=x%10;
        x/=10;
    }
    return dfs(len-1,true,true);
}
int main(){
    //ios::sync_with_stdio(false);
    //freopen("in","r",stdin);
    C[0][0]=1;
    rep(i,1,20){
        C[i][0]=1;
        rep(j,1,i){
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
