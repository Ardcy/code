#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,m,k,q;
const int N = 2e5+6;
int jc[N+5],inv[N+5];
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}return ans;
}
void ini(){
	inv[0] = 1;
	jc[0] = 1; 
	for(int i=1;i<=N;i++){
		jc[i] = jc[i-1]*i%mod;
	}
	inv[N] = qp(jc[N],mod-2);
	for(int i=N-1;i>=1;i--){
		inv[i] = inv[i+1] * (i+1) %mod; 
	}
}
int C(int x,int y){
	return jc[x] * inv[y] %mod * inv[x -y]%mod;
}
int solve(int x){
	cout << x << endl;
	int ans = 0;
	int k1 = k;
	int x1 = x;
	if(k1 > x1){
		k1 = x1;
	}
	for(int i=0;i<=k1;i++){
		ans += C(x1,i);
	}
	if(x1 <= m){
		return ans;
	}
	cout << " ans = " << ans << endl;
	
	if(x>m)ans -= solve(x - m);
	return ans;
}
signed main(){
	ini();
	cin >> n >> m >> k >> q;
	k-=1;
	while(q--){
		int u,v;
		cin >> u >> v;
		int x = abs(u-v);
		cout << solve(x-1) << endl;
	}

}