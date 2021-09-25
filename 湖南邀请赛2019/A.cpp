#include<bits/stdc++.h>
#define int long long
#define double long double
#define sf(n) scanf("%lld",&n)
#define sff(a,b) scanf("%lld%lld",&a,&b)
#define sfff(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define debug printf("Here\n");
#define out(x) printf("%lld\n",x)
#define out2(x,y) cout << x <<" " << y << endl
#define out3(x,y,z) cout << x << " " << y << " " << z << endl
#define pb push_back
#define fi first
#define se second 
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size)
using namespace std;

const int MAXN = 2e5 + 10;

int arr[MAXN], suf[MAXN];

signed main(){
	
	int n;
	
	while(~sf(n)) {
		for (int i = 0; i <= n + 1; i++) suf[i] = 0;
		for (int i = 0; i <= n; i++) sf(arr[i]);
		for (int i = n; i >= 0; i--) suf[i] = suf[i + 1] + arr[i];
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			if (suf[i] >= i) {
				ans = max(ans, i);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
