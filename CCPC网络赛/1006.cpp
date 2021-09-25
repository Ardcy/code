#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

typedef long long LL;

int prime[N], id1[N], id2[N], flag[N], ncnt, m;

LL g[N], sum[N], a[N], T, n;

inline int ID(LL x) {
    return x <= T ? id1[x] : id2[n / x];
}

inline LL calc(LL x) {
    return x * (x + 1) / 2 - 1;
}

inline LL f(LL x) {
    return x;
}

inline void init() {
    T = sqrt(n + 0.5);
    for (int i = 2; i <= T; i++) {
        if (!flag[i]) prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
        for (int j = 1; j <= ncnt && i * prime[j] <= T; j++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (LL l = 1; l <= n; l = n / (n / l) + 1) {
        a[++m] = n / l;
        if (a[m] <= T) id1[a[m]] = m; else id2[n / a[m]] = m;
        g[m] = calc(a[m]);
    }
    for (int i = 1; i <= ncnt; i++) 
        for (int j = 1; j <= m && (LL)prime[i] * prime[i] <= a[j]; j++) 
            g[j] = g[j] - (LL)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
}

inline LL solve(LL x) {
    if (x <= 1) return x;
    return n = x, init(), g[ID(n)];
}

void my_init() {
    for(int i=0; i< N; i++) {
        prime[i]=0, id1[i]=0, id2[i]=0, flag[i]=0;
        g[i] = 0, sum[i] = 0, a[i] = 0;
        T = 0, ncnt =0, n =0, m=0;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        LL n, mod;
        my_init();
        cin >> n >> mod;
        if (n % 2 == 0) {
            
            cout << (solve(n+1)%mod+(3+n+1)/2%mod*(n-1)%mod-2 + mod)%mod << endl;
        } else {
            cout << (solve(n+1)%mod+(3+n+1)%mod*(n-1)/2%mod-2 + mod)%mod << endl;
        }
        // scanf("%lld %lld", &n, &mod);
        // printf("%lld\n", (solve(n+1)+(3+n+1)*(n-1)/2-2)%mod);
    }
    
}

