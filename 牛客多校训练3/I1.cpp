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

vector<pair<int, int> > vec[550];
vector<pair<int, int> > status[550];
int is_repair[550], dist[550];
int n, m, t, d, ans;
int martix[550][550];

struct Node {
    int u, d, s;
};

void BFS() {
    queue<Node> que;
    que.push(Node{1, d, 0});
    dist[1] = 0;
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        int u = temp.u, ds = temp.d, s = temp.s;
        if (u == n) {
            ans = min(ans, s);
            continue;
        }
        for (int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i].first, w = vec[u][i].second;
            if (w > ds) continue;
            if (is_repair[v] && w + s < dist[v]) {
                dist[v] = w + s;
                que.push(Node{v, d, w + s});
                continue;
            }
            if (!is_repair[v]) {
                int flag = 1;
                for (int i = 0; i < status[v].size(); i++) {
                    int ts = status[v][i].first, td = status[v][i].second;
                    if (s + w >= ts && ds - w <= td) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    status[v].push_back(make_pair(s + w, ds - w));
                    que.push(Node{v, ds - w, w + s});
                }
            }
        }

    }
}

signed main(){

    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    cin >> n >> m >> t >> d;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        for (int j = 1; j <= n; j++)
            martix[i][j] = INF;
        martix[i][i] = 0;
    }
    for (int i = 1; i <= t; i++) {
        int k;
        cin >> k;
        is_repair[k] = 1;
    }
    is_repair[1] = 1, is_repair[n] = 1;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w > d) w = INF;
        martix[u][v] = w;
        martix[v][u] = w;
        vec[u].push_back(make_pair(v, w));
        vec[v].push_back(make_pair(u, w));
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (martix[i][k] + martix[k][j] < martix[i][j]) {
                    martix[i][j] = martix[i][k] + martix[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (martix[i][j] > d)
                martix[i][j] = INF;
        }    
    }
    // cout << martix[1][n] << endl;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!is_repair[i] || !is_repair[j] || !is_repair[k]) continue;
                if (martix[i][k] + martix[k][j] < martix[i][j]) {
                    martix[i][j] = martix[i][k] + martix[k][j];
                }
            }
        }
    }

    ans =  martix[1][n];
    // BFS();
    if (ans != INF)
        cout << ans << endl;
    else
        cout << "stuck" << endl;

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