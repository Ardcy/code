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
#define double long double
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-6;

template<class T>
inline void read(T &res);

void yes(){ cout << "YES" << endl; }
void no(){ cout << "NO" << endl; }

void init(int n){
    for(int i = 1; i <= n; i++){
        
    }
}
int flag[maxn], b[maxn];

vector<int> vec[15];
int n, s, m;

int solve(int k, int pre, int end) {
    set<int> S;
    for (int i = pre; i <= end; i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            S.insert(vec[i][j]);
        }
    }
    if (S.size() < m) return -1;
    int res = end - s + end - pre + k - pre + abs(k - s);
    int res2 = s - pre + end - pre + end - k + abs(k - s);
    return min(res, res2);

}

signed main(){

    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int kcase = 0;
    while (cin >> n >> s >> m) {
        if (n == 0 && s == 0 && m == 0) break;
        kcase++;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            vec[i].clear();
            flag[i] = 0;
            for (int j = 1; j <= k; j++) {
                int t;
                cin >> t;
                vec[i].push_back(t);
            }
            string opt;
            cin >> opt;
            if (opt[0] == 'Y') {
                flag[i] = 1;
            }
        }
        int ans = -1;
        
        for (int pre = 1;  pre <= s; pre++) {
            for (int end = s; end <= n; end++) {
                int res = solve(s, pre, end);
                int flag1 = 0;
                for(int j = pre;j<=end;j++){
                	if(flag[j])flag1 = 1;
                }
                if (res == -1) continue;
                if (ans == -1 && flag1) ans = res;
                else if(flag1)ans = min(ans, res);
            }
        }
    
        if (ans == -1) {
            cout << "Test case #" << kcase <<": Impossible" << endl << endl;
        } else {
            cout << "Test case #" << kcase <<": " << ans << endl << endl;
        }

    }
    
    

    return 0;
}

template<class T>
inline void read(T &res)
{
    char c;
    T flag = 1;
    while((c = getchar()) < '0'|| c > '9')
        if (c == '-') flag = -1; res = c - '0';
    while((c = getchar()) >= '0' && c <= '9')
        res = res * 10 + c - '0'; res *= flag;
}