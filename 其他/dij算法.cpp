#include<bits/stdc++.h> 
using namespace std;
#define mn 100010
#define inf 1 << 30
struct edge{
    int v, nxt, w;
} e[mn<<1];
int h[mn],p;
inline void add(int a,int b,int c){
    p++;
    e[p].nxt = h[a];
    h[a] = p;
    e[p].v = b;
    e[p].w = c;
}
struct node{
    int u,v;
    bool operator <(const node &b) const{
        return u > b.u;
    }
};
int n, m, s, t;
int dis[mn];
priority_queue<node> q;
inline void Dij(int s){
    for(int i=0;i<=n;i++)
        dis[i] = inf;
    dis[s] = 0;
    node o;
    o.u = 0;
    o.v = s;
    q.push(o);
    while (q.size()){
        int u = q.top().v;
        int d = q.top().u;
        q.pop();
        if(d!=dis[u])
            continue;
		for (int i = h[u]; i; i = e[i].nxt){
            int v = e[i].v;
            int w = e[i].w;
            if (dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                node p;
                p.u = dis[v], p.v = v;
                q.push(p);
            }
        }
    }
}
int main(){
    cin>>n>>m>>s>>t;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        add(u, v, w);
        add(v, u, w);
    }
    Dij(s);
    cout << dis[t] <<endl;
    return 0;
}
