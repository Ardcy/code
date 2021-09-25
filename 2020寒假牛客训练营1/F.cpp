#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[100010];
struct Node{
    int v,to;
}e[200010];
int h[100010],ee=1;
void addedge(int u,int v){
    e[ee].v=v,e[ee].to=h[u];
    h[u]=ee++;
}
int ans,ans2;
int Dfs(int u,int pa){
    int res=0,res2=0;
    for(int i=h[u];i!=0;i=e[i].to){
        int x=e[i].v;
        if(x==pa) continue;
        if(s[x-1]=='B') continue;
        else if(s[x-1]=='W') res=Dfs(x,u)+1,res2+=res;
        if(s[u-1]=='B')
            ans-=(res-1)*res/2;
    }
    return res2;
}
signed main(){
    int n;
    cin>>n;
    cin>>s;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(s[i]=='B'){
            int k=Dfs(i+1,0);
            res+=k+(k)*(k-1)/2;
        }
    }
    cout<<res+ans<<endl;
    return 0;
}
