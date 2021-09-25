#include<bits/stdc++.h>
using namespace std;
const int kMaxN = 400 * 1000;
#define ll long long 
int n;
const int mod=984235344;
int facts[kMaxN];
 
int main() {
	facts[0]= 1;
	for (int i = 1; i < kMaxN; ++i) {
		facts[i] = (ll)facts[i - 1] * i % mod;
	}
 	int T=20;
	int ans = 0;
	while(T--){
		ans = 0;
		n=T;
		for (int len = 1; len <= n; ++len) {
			int coef = (ll)(n - len + 1) * (n - len + 1) % mod;
			coef = (ll)coef * facts[len] % mod;
			coef = (ll)coef * facts[n - len] % mod;
			ans = (ans + coef) % mod;
		}
	cout << ans << "\n";	
	}
	
}
