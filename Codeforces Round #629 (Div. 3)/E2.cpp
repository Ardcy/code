#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 200005;

vector <int> g[N];
int n,m,t1,t2,t3,dep[N],fa[N][20];

void dfs(int p) {
    for(int q:g[p]) {
        if(dep[q]) continue;
        dep[q]=dep[p]+1;
        fa[q][0]=p;
        dfs(q);
    }
}

int lca(int p,int q) {
    if(dep[p]<dep[q]) swap(p,q);
    for(int i=18;i>=0;--i) if(dep[fa[p][i]]>=dep[q]) p=fa[p][i];
    for(int i=18;i>=0;--i) if(fa[p][i]-fa[q][i]) p=fa[p][i],q=fa[q][i];
    if(p-q) return fa[p][0];
    else return p;
}

bool cmp(const int &p,const int &q) {
    return dep[p]<dep[q];
}

signed main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<n;i++) {
        cin>>t1>>t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dep[1]=1;
    dfs(1);
    for(int i=1;i<=18;i++) {
        for(int j=1;j<=n;j++) {
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=m;i++) {
        int k;
        cin>>k;
        vector <int> vec;
        for(int j=0;j<k;j++) {
            int t;
            cin>>t;
            vec.push_back(t);
        }
        sort(vec.begin(),vec.end(),cmp);
        int fg=1;
        for(int j=1;j<k;j++) {
            int p=vec[j],q=vec[j-1];
            int l=lca(p,q);
            cout<<l<<endl;
            if(dep[p]-dep[l]>1 && dep[q]-dep[l]>1) fg=0;
        }
        cout<<(fg?"YES":"NO")<<endl;
    }
}
