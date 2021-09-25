#include <iostream>
#include <cstdio>
#define int long long 

using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
signed main() {
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int MAX = min(c, d), ans = 0;

	int sum = 0;
	for(int i = 0; i <= a; i++){
		int k = d - i;
		if(k < 0) break;
		sum += min(k, b) + 1;
	}
	int t = max(0ll, d - c);
	int sum2 = 0;
	for(int i = 0; i <= a; i++){
		int k = t - i;
		if(k < 0) break;
		sum2 += min(k, b) + 1;
	}
	ans += (MAX + 1) * (sum2 - 1);
	int cc = sum - sum2 + 1;
	int c2;
	for(int i = 1; i <= maxn; i++) {
		if((1 + i) * i / 2 == cc) {
			c2 = i;
			break;
		}
	}
	for(int i = 1; i <= c2 + 1; i++) {
		ans += i * (c2 - i + 2);
	}
	cout << ans << endl;
	return 0;
}

