#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 5e5 + 5;
const int INF = 0x3f3f3f3f;
const ull seed = 131;
const ll MOD = 1e9;
using namespace std;
int num[maxn], sum[21][maxn];
int mu[maxn], vis[maxn];
int prime[maxn], cnt;
void getmu(int n){
    memset(vis, 0, sizeof(vis));
    memset(mu, 0, sizeof(mu));
    memset(num, 0, sizeof(num));
    cnt = 0;
    mu[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]){
            prime[cnt++] = i;
            mu[i] = -1;
            num[i] = 1;
        }
        for(int j = 0; j < cnt && prime[j] * i <= n; j++){
            vis[i * prime[j]] = 1;
            num[i * prime[j]] = num[i] + 1;
            if(i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
    }
}
 
void init(){
    memset(sum, 0, sizeof(sum));    //sum[p][d]:d的除数的质因子个数为p的sum(mu)
    for(int i = 1; i <= 5e5; i++){
        for(int j = i; j <= 5e5; j += i){
            sum[num[i]][j] += mu[j / i];
        }
    }
    for(int i = 1; i <= 5e5; i++){  //d的除数质因子个数小于p的sum(mu)
        for(int j = 1; j <= 19; j++){
            sum[j][i] += sum[j - 1][i];
        }
    }
 
    for(int i = 1; i <= 5e5; i++){
        for(int j = 0; j <= 19; j++){
            sum[j][i] += sum[j][i - 1];
        }
    }
}
int main(){
    getmu(5e5);
    init();
    ll n, m;
    int p, T;
    scanf("%d", &T);
    while(T--){
        ll ans = 0;
        scanf("%lld%lld%d", &n, &m, &p);
        if(p > 19){
            printf("%lld\n", n * m);
            continue;
        }
        for(int i = 1; i <= min(n, m);){
            int l, r;
            l = i, r = min(n / (n / i), m / (m / i));
            ans += 1LL * (n / i) * (m / i) * (sum[p][r] - sum[p][l - 1]);
            i = r + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
 
 
 