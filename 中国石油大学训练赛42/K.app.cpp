#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N = 200009;
int n, MN, cnt;
string g[N];
map<string, int>f;
map<string, bool>p;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> g[i];
        f[g[i]]++;
    }
    for(map<string, int>::iterator it = f.begin(); it != f.end(); it++)
        MN = max(MN, it->second);
    sort(g+1, g+n+1);
    int m;
    for(int i = 1; i <= n; i++)
    {
        if(f[g[i]] != MN) continue;
        m = g[i].length();
        for(int j = 0; j < m; j++)
            putchar(g[i][j]);
        putchar('\n');
        f[g[i]] = 0;
    }
    return 0;
}
