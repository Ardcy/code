#include <bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
#define pb push_back
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld%lld", &a, &b)
#define sfff(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)
#define debug printf("Here\n")
#define out(x) cout << x << endl
#define out2(x, y) cout << x << " " << y << endl
#define out3(x, y, z) cout << x << " " << y << " " << z << endl
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define divider cout << "-------------------------" << endl;
using namespace std;
 
inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
 
const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const double eps = 1e-9;
const double PI = acos(-1.0);
 
int n, m, k, q;
 
int dp[2][MAXN];
 
signed main()
{
    n = read(), m = read(), k = read(), q = read();
    for (int i = 0; i <= m; i++)
    {
    	dp[1][i] = 1;
    }
    for (int i = 2; i <= k; i++)
    {
    	int sum = 1;
    	dp[i & 1][0] = 1;
    	for (int j = 1; j <= n; j++)
    	{
    		dp[i & 1][j] = sum;
    		sum = (sum + dp[(i - 1) & 1][j]) % MOD;
    		if (j >= m)
    		{
    			sum = ((sum - dp[(i - 1) & 1][j - m]) % MOD + MOD) % MOD;
    		}
    	}
    }
    while (q--)
    {
    	int u = read(), v = read();
    	int len = abs(u - v);
    	cout << dp[k & 1][len] << endl;
    }
    return 0;
}