#include<bits/stdc++.h>
using namespace std;
#define mn 100010
#define inf 1<<30
struct edge{
	int nex;
	int to;
	double w;
}e[mn<<1];
int h[mn],p;
void add(int a,int b,int c){
	p++;
	e[p].to=b;
	e[p].w=c;
	e[p].nex=h[a];
	h[a]=p; 
}
struct node{
	int u,v;

};
int m,n,s,t;
int dis[mn];
priority_queue<node>q;
void dij(int s){
	for(int i=1;i<=n;i++){
		dis[i]=inf;
	}
	dis[s]=0;
	node R;
	R.u=0;
	R.v=s;
	q.push(R);
	while(q.size()){
		int u=q.top().v;
		int d=q.top().u;
		q.pop();
		if(d!=dis[u])
			continue;
		for(int i=h[u];i;i=e[i].nex)
		{
			int v=e[i].to;
			int w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				node p;
				p.u = dis[v];
				p.v = v;
				q.push(p);
			}
		}
	} 
}
int main(){
	cin>>n>>m>>s>>t;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}	
	dij(s);
	cout<<dis[t]<<endl;
}
