#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 +10;
struct Node{
    int v,next;
}e[2*maxn];
int h[maxn],ee=1,parent[maxn];
struct node{
    int dep,idx,c;
}deep[maxn];
void add(int u,int v){
    e[ee] = Node{v,h[u]};
    h[u]=ee++;
}
int dfs(int u,int pre,int dep){
    parent[u] = pre;
    deep[u].dep = dep;
    deep[u].idx = u;
    int res = 1;
    for(int i=h[u];i!=0;i=e[i].next){
        int v = e[i].v;
        if(v == pre) continue;
        res += dfs(v,u,dep+1);
    }
    deep[u].c = res;
    return res;  
}
bool cmp(node a,node b){
	return a.dep-a.c<b.dep-b.c;
}
signed main(){
    int n,k,kk=0;
    cin>>n>>k;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u); 
    }
    dfs(1,0,1);
    sort(deep+1,deep+1+n,cmp);
    int ans=0;
    for(int i=1;i<=k;i++) ans += deep[i].dep;
    for(int i=1;i<=k;i++) ans -= deep[i].c;
    cout<<ans<<endl;
    return 0;
}
