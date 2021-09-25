#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+5;
int arr[N];
int brr[N];
int crr[N];
const int mod = 1e9+ 7;
const int mod1 = 998244353;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans *= a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}

signed main(){

	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[n+1-i]);
	}
	brr[1] = 1;crr[1] = 1;
	for(int i=1;i<=n;i++){
		brr[i] = brr[i-1] * N + arr[i];
		brr[i] %= mod;
		crr[i] = crr[i-1] * N + arr[i];
		crr[i] %= mod;
	}
	int ans1 = mod;
	int x1=0,y1=0;
	for(int i=1;i<=n;i++)
	{
		int length = i;
		for(int j=2*i;j<=n;j+=i){
			int pre = brr[j] * brr[j-i-i] % mod;
			int prepre = brr[j-i] * brr[j-i] % mod;
			if(pre == prepre){
				length = j;
			}else{
				break;
			}
		}
		int ans = length;
		for(int j = length+1;j<=n;j++){
			if(arr[j] == arr[j-length]){
				ans++;
			}
		}
		if(n-ans+i<ans1){
			x1 = n-ans,y1 = i;
			ans1 = x1+y1;
		}
	}
	cout  << x1 << " " << y1 << endl;
}	