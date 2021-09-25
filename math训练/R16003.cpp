#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int mod = 1e9+7;
ll qkc(ll a,ll b,ll mod)   //乘法
{
    ll ans = 0;
    while(b){
        if (b & 1)
            ans = (ans + a) % mod;
        a = (a << 1) % mod;   // a = a * 2 % mod;
        b /= 2;
    }
    return ans;
}
ll qkpow(ll a,ll b,ll mod)
{
	ll ans = 1;
	while(b){
		if (b & 1)  // b % 2 == 1
			ans = qkc(ans,a,mod);
		a = qkc(a,a,mod);
		b /= 2;
	}
	return ans;
}
bool Miller_Rabin(ll n){
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
		return 1;
	if (n % 2 == 0 || n == 1)
		return 0;
	ll k = 0,m = n - 1;
	while(!(m & 1)){     // m % 2 == 0;
		m >>= 1;   // m /= 2;
		k++;
	}
	for(int i = 1;i <= 20;i++){  // i的上限不定，越高越准，一般十几就行了
		ll a = rand() % (n - 1) + 1,x;
		x = qkpow(a,m,n);
		for(int j = 1;j <= k;j++){
			ll y = qkc(x,x,n);
			if (y == 1 && x != 1 && x != n - 1)
				return 0;
			x = y;
		}
		if (x != 1)
			return 0;
	}
    return 1;
}
signed main(){
	int n;
	cin>>n;
	if(Miller_Rabin(n)){
		cout<<1<<endl;return 0;
	}
	if(n%2==0){
		cout<<2<<endl;return 0;
	}
	if(Miller_Rabin(n-2)){
		cout<<2<<endl;
	}else cout<<3<<endl;
	return 0;
}
