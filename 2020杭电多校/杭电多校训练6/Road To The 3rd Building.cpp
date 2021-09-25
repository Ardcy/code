#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N],pre[N];
int jc[N];
int ny[N];
const int mod = 1e9+7;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1) ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
int summ[N];
signed main(){
	int t;
	jc[0] = 1;
	for(int i=1;i<N;i++){
		jc[i] = jc[i-1] * i % mod;
	}


	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			scanf("%lld",&arr[i]);		
			pre[i] = pre[i-1]+arr[i];
			pre[i] %= mod;
		}
		int sum = 0;
		int ans = 0;
		for(int i=1;i<=(n+1)/2;i++){
			summ[i] = summ[i-1] + pre[n+1-i] - pre[i-1];
			while(summ[i]<0)summ[i]+=mod;
			while(summ[i]>=mod)summ[i]-=mod;
		}
		for(int i=1;i<=n;i++){
			int p = min(i,n+1-i);
			sum = summ[p];
		//	cout << sum << endl;
			sum *= qp(i,mod - 2);
			ans += sum;
			ans %= mod;
		}
		// cout << ans << endl;
		// cout << 25 * qp(12,mod-2) %mod << endl;
		cout << (ans * qp(n*(n+1)/2%mod,mod-2)%mod) <<endl;

	}
}