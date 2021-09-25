/*
	链式前向星存图的本质在于
	将一条边的起点、终点、边权中的起点 改变为存该起点的前一条边 
	
*/

#include<bits/stdc++.h>
using namespace std;
#define maxn 2000010
#define LL inline
#define M(x,y) make_pair(x,y)
int n,m,tot=0,cnt=0,ans;
int first[maxn],vis[maxn];
struct edge{
	int nextx,to,val;
}e[maxn];
void add(int u,int v,int w){
	tot++;
	e[tot].nextx = first[u];
	first[u] = tot;
	e[tot].to = v;
	e[tot].val = w;
}

priority_queue<pair<int,int> >Q;
int prim(){
	Q.push(M(0,1));
	while(!Q.empty()&&cnt<n){
		int now = Q.top().second;
		int w = Q.top().first;
		Q.pop();
		if(vis[now])continue;
		vis[now]=1;
		ans+=w;
		cnt++;
		for(int i=first[now];i;i=e[i].nextx)
			if(!vis[e[i].to])
			Q.push(M(-e[i].val,e[i].to) ) ;
	}
	return -ans;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	cout<<prim()<<endl;
	return 0;
}
