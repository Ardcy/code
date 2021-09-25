#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int q;
	for(cin >> q; q; q -= 1){
		int n, m;
		cin >> n >> m;
		int ans = 0, s = 0;
		for(int i = 1; i <= 10; i += 1) s += m * i % 10;
		n = n / m * m;
		ans += n / m / 10 * s;
		for(int i = n / m / 10 * m * 10 + m; i <= n; i += m) ans += i % 10;
		cout << ans << "\n";
	}
	return 0;
}
