#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <array>
#include <cstring>
#include <unordered_map>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-6;

int cnt[300];
signed main(){

    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    cin >> T;
    int cast = 0;
    while(T--) {
        ++cast;
        string s;
        cin >> s;
        for (int i = 0; i <= 256; i++) cnt[i] = 0;
        for (auto c : s) {
            cnt[c]++;
        }
        int ans = 0;
        for (int i = 0; i <= 256; i++)
            ans = max(ans, cnt[i]);
        
        cout << "Case #" << cast << ": " << ans << endl;
    }
    return 0;
}
