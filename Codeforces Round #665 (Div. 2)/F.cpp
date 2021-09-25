#include<bits/stdc++.h>
using namespace std;

const int Maxn = 500010,MaxM = 500010;
struct edge{
	int to,dis,next;
};

edge e[Maxn];
int head[Maxn],dis[Maxn],cnt;
int n,m,s;
bool vis[Maxn];
void addedge(int u,int v,int d){
	e[++cnt].dis = d;
	e[cnt].to = v;
	e[cnt].next = head[u];
	head[u]=cnt;
}
struct node{
	int dis,pos;
	bool operator <(const node &x)const{
		return x.dis<dis;
	}
};
priority_queue<node>q;
void dijkstra(){
	dis[s] = 0;
	q.push((node){0,s});
	while(!q.empty()){
		node tmp = q.top();
		q.pop();
		int x = tmp.pos,d = tmp.dis;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next){
			int y = e[i].to;
			if(dis[y]>dis[x]+e[i].dis){
				dis[y]=dis[x]+e[i].dis;
				if(!vis[y])q.push((node){dis[y],y});
			}
		}
	} 
}

int main()
{
    scanf( "%d%d%d", &n, &m, &s );
    for(int i = 1; i <= n; ++i)dis[i] = 0x7fffffff;
    for( register int i = 0; i < m; ++i )
    {
        register int u, v, d;
        scanf( "%d%d%d", &u, &v, &d );
        addedge( u, v, d );
    }
    dijkstra();
    for( int i = 1; i <= n; i++ )
        printf( "%d ", dis[i] );
    return 0;
}
