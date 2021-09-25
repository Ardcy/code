#include<bits/stdc++.h> 
using namespace std;
const int N = 100005,INF = 0x3f3f3f3f;
int fa[N],vis[N],flag=1,n,m;
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int x,y,i=1;i<=m;++i){
        cin>>x>>y;
        if(find(x)!=find(y))
			vis[find(y)]=vis[find(y)]|vis[find(x)],fa[find(x)]=find(y);
        else 
			vis[find(x)]=1;
    }
    for(int i=1;i<=n;i++)if(!vis[find(i)])flag=0;
    if(flag)cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;
    return 0;
}









