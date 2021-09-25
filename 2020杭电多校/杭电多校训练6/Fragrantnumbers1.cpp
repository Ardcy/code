#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
const int maxn = 5005;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

char s[30] = "011451419191145141919";
int ans[maxn];
int vis[16][16][5005];
vector<int>f[16][16];

ll get(int l,int r) {
    ll tmp = 0;
    for(int i = l;i <= r;i++) {
        tmp = tmp * 10 + s[i] - '0';
    }
    return tmp;
}

void init() {
    for(int i = 1;i <= 15;i++) {
        for(int j = i;j <= 15;j++) {
            ll num = get(i,j);
            if(num <= 5000) {
                f[i][j].push_back(num);
                vis[i][j][num] = 1;
            }
        }
    }
}

int main() {
    init();
    for(int l = 1;l <= 15;l++) { //长度
        for(int i = 1;i + l - 1 <= 15;i++) { //起点
            int j = i + l - 1;
            for(int k = i;k < j;k++) {
                for(int it1 = 0;it1 < f[i][k].size();it1++) {
                    for(int it2 = 0;it2 < f[k + 1][j].size();it2++) {
                        int num1 = f[i][k][it1],num2 = f[k + 1][j][it2];
                        if(num1 + num2 <= 5000 && !vis[i][j][num1 + num2]) {
                            f[i][j].push_back(num1 + num2);
                            vis[i][j][num1 + num2] = 1;
                        }
                        if(num1 * num2 <= 5000 && !vis[i][j][num1 * num2]) {
                            f[i][j].push_back(num1 * num2);
                            vis[i][j][num1 * num2] = 1;
                        }
                    }
                }
            }
        }
    }
    
    memset(ans,0x3f,sizeof(ans));
    for(int i = 1;i <= 15;i++) {
        for(auto it = f[1][i].begin();it != f[1][i].end();it++) {
            int num = *it;
            if(num <= 5000) ans[num] = min(ans[num],i);
        }
    }
    
//    for(int i = 1;i <= 5000;i++) {
//        printf("%d ",ans[i]);
//    }
    int T;scanf("%d",&T);
    while(T--) {
        int n;scanf("%d",&n);
        if(ans[n] == INF) printf("-1\n");
        else printf("%d\n",ans[n]);
    }
    return 0;
}
