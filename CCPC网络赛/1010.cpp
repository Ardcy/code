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
 
const int MAXN = 50 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const double PI = acos(-1.0);
 
int n, m, k;
 
int arr[MAXN];
 
signed main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T = read();
    while (T--)
    {
        n = read();
        for (int i = 0; i < n; i++)
        {
            arr[i] = read();
        }
        int sum = 0;
        int flag = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] == arr[i-1]){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout <<"YES" << endl;
        }
        else{
            cout <<"NO" << endl;
        }
    }
    return 0;
}
