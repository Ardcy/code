#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define fors(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const ll mod = 100000000000000003LL;
ll mul(ll a,ll b){

	if(a < sqrt(mod) && b < sqrt(mod)){
		return a*b;
	}
	ll res = 0;
	while(b){
		if(b&1)res = (res + a)%mod;
		a = (a+a)%mod;
		b >>= 1;
	}
	return res;
}
ll qm(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1)res = mul(res,a);
		a = mul(a,a);
		b >>= 1;
	}
	return res;
}
ll fac[20],ifac[20];
int a[25],cnt;
int d;
int cur[10];
int lim[10];
ll A[20],B[20],C[20];
void mul(){
	for(int i=0;i<20;i++){
		C[i] = 0;
		for(int j=0;j<=i;j++){
			int k = i-j;
			C[i] = (C[i] + mul(A[j],B[k]))%mod;

		}
	}
	for(int i=0;i<20;i++){
		A[i] = C[i];
	}
}
int Com(int n,int k){
	return mul(mul(fac[n],ifac[k]),ifac[n-k]);
}
ll get_ans(int len){
	if(len==0)return 1;
	fors(i,0,20)A[i] = 0;
	A[0] = 1;
	fors(i,0,10){
		if(i==d)continue;
		fors(j,0,20){
			if(j<=lim[i]){
				B[j] = ifac[j];
			}
			else{
				B[j] =0;
			}
		}
		mul();
	}
	ll ans = mul(fac[len],A[len]);
	return ans;
}
map<ll,ll>mp[18][19];
ll no_lim(int len){
	if(len ==0){
		fors(i,0,10){
			if(i!=d&&cur[i]>=cur[d])return 0;
		}
		return 1;
	}
	int cnt[19];
	fors(i,0,19)cnt[i] = 0;
	fors(i,0,10)if(i!=d)cnt[cur[i]]++;
	ll state =  0;
	for(int i=18;i>=0;i--){
		state = state*10 + cnt[i];
	}
	if(mp[len][cur[d]].find(state)!=mp[len][cur[d]].end())return mp[len][cur[d]][state];
	ll ans  = 0;
	int sum = 0;
	fors(i,0,10)sum += cur[i];
	sum += len;
	int down = (sum+18)/10;
	int up_half = sum/2;
	for(int d_num = down;d_num <= up_half;++d_num){
		if(d_num < cur[d])continue;
		if(d_num-cur[d] > len)break;
		int flag = 1;
		fors(i,0,10){
			if(i==d)continue;
			if(cur[i]>=d_num){
				flag = 0;break;
			}
			lim[i] = d_num - 1 - cur[i];
		}
		if(!flag)continue;
		int need_d = d_num - cur[d];
		ans = (ans + mul(Com(len,need_d),get_ans(len - need_d)))%mod;
	}
	for(int i= up_half+1;i<=sum;i++){
		if(i<cur[d])continue;
		int need_d = i-cur[d];
		if(len < need_d)break;
		ll t = Com(len,need_d);
		fors(j,0,len-need_d)t = t*9%mod;
		ans = (ans + t)%mod;
	}
	mp[len][cur[d]][state] = ans;
	return ans;
}
ll sol(ll x){
	if(x<10)return x>=d;
	cnt = 0;
	while(x){
		a[++cnt] = x%10;x/=10;
	}
	ll ans = 0;
	for(int i=cnt;i>0;i--){
		int down = 1;
		if(i<cnt)down = 0;
		for(int j= down;j<a[i];j++){
			cur[j]++;
			ans = (ans+no_lim(i-1))%mod;
			cur[j]--;
		}
		cur[a[i]]++;
	}
	ans = (ans + no_lim(0))%mod;
	memset(cur,0,sizeof(cur));
	for(int i=cnt-1;i>0;i--){
		for(int j=1;j<10;j++){
			cur[j]++;
			ans = (ans+no_lim(i-1))%mod;
			cur[j]--;
		}
	}
	if(d==0)ans++;
	return ans;
}
int main(){
	ifac[0] = fac[0] = 1;
	fors(i,1,20)fac[i] = mul(fac[i-1],i),ifac[i] = qm(fac[i],mod-2);
	int T;
	cin >> T;
	while(T--){
		ll l,r;
		scanf("%lld%lld%d",&l,&r,&d);
		printf("%lld\n",sol(r) - sol(l-1));
	}
}