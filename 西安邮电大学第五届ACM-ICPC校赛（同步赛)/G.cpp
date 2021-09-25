#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <limits.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <bitset>
#include <cassert>
#include <complex>
#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <vector>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#define int long long
#define double long double
using namespace std;

const int MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const double PI = acos(-1.0);

int n;

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

int num[MAXN];

int l[MAXN], r[MAXN], lisan[MAXN];

signed main()
{
    int T = read();
    while (T--)
    {
        n = read();
        for (int i = 0; i <= 2 * n; i++)
        {
            num[i] = 0;
        }
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            l[i] = read(), r[i] = read();
            lisan[idx++] = l[i];
            lisan[idx++] = r[i];
        }
        sort(lisan, lisan + idx);
        idx = unique(lisan, lisan + idx) - lisan;
        for (int i = 0; i < n; i++)
        {
            int a = lower_bound(lisan, lisan + idx, l[i]) - lisan;
            int b = lower_bound(lisan, lisan + idx, r[i]) - lisan;
            num[a]++;
            num[b]--;
        }
        for (int i = 1; i < n; i++)
        {
            num[i] = num[i - 1] + num[i];
        }
        int maxV = 0;
        for (int i = 0; i < n; i++)
        {
            maxV = max(maxV, num[i]);
        }
        cout << idx << " " << maxV << endl;
    }
    return 0;
}

