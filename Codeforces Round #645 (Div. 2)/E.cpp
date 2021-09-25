#include<bits/stdc++.h>
using namespace std;
 #define int long long
long long a[5000010];
 
int main() {
    int n, m;
    long long x, sum = 0;
    scanf("%d", &n);
    m = (n + 1) / 2;
    for(int i = 1; i <= m; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    scanf("%lld", &x);
    sum += (n - m) * x;
    if(sum > 0) {
        printf("%d\n", n);
        return 0;
    }
    int y = n - m;
    long long s = 0;
    int flag = 1;
    for(int i = 1; i <= y; i++) s += a[i];
    if(s <= 0) flag = 0;
    for(int i = 1; i <= m; i++) {
        s -= a[i];
        s += a[y + i];
        if(s <= 0) flag = 0;
    }
    if(flag == 1) {
        printf("%d\n", y);
        return 0;
    }
    long long now = 0, mx = 0, mxi = 0;
    for(int i = 1; i < m; i++) {
        now += a[i] - x;
        if(now > mx) {
            mx = now;
            mxi = i;
        }
        long long c = mx + i * x;
        if(sum - c > 0) {
            printf("%d\n", n - i);
            return 0;
        }
    }
    printf("-1\n");
    
    return 0;
}
