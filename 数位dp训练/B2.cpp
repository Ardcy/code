#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;

int T, cases = 0, K, digit[20];
ll L, R, dp[20][1100][10];

ll dfs(int pos, int state, int len, int first, int limit)
{ // len:已有长度， state:状压，first:前导0 
    if (pos == -1) return len == K;
    if (len > K) return 0;
    if (!limit && dp[pos][state][K] != -1) return dp[pos][state][K];
    int last = limit ? digit[pos] : 9;
    ll ret = 0;
    for (int i = 0; i <= last; ++i) {
        int next_state = state, next_len = len;
        if((i != 0 || (!first && i == 0)) && state < (1 << i)) { // i是最大数字
            next_state += (1 << i);
            next_len++;
        } else if (((state >> i) & 1) == 0){ 
            int k = i + 1;
            while (k != 10 && ((state >> k) & 1) == 0) ++k; // 使子序列潜力变大
            if (k != 10) {
                next_state = next_state - (1 << k) + (1 << i);
            }
        }
        ret += dfs(pos - 1, next_state, next_len, first && (i == 0), limit && (i == last));
    }
    if (!limit) dp[pos][state][K] = ret;
    return ret;
}

ll solve(ll x)
{
    if (x == 0) return 0;
    memset(digit, 0, sizeof (digit));
    int len = 0;
    while (x) {
        digit[len++] = x % 10;
        x /= 10;
    }
    return dfs(len - 1, 0, 0, 1, 1);
}

int main()
{
    memset(dp, -1, sizeof (dp));
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%d", &L, &R, &K);
        printf("Case #%d: %lld\n", ++cases, solve(R) - solve(L - 1));
    }
    return 0;
}