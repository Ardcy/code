#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long LL;
typedef pair<LL,int> P;
const int maxn = 1e3+7;
struct Edge{
	int to,next;LL val;
}edge[maxn*100];
struct Line{
	int to,next;LL val;
}line[maxn*100];
int n,m,s,e,tot,k,head[maxn],revhead[maxn];
int tot2;
bool vis[maxn];
LL dist[maxn];
inline void addEdge(int a,int b,LL c){
	edge[tot].to=b;
	edge[tot].next=head[a];
	edge[tot].val=c;
	head[a]=tot++;
}
inline void AddEdge(int a,int b,LL c){
	line[tot2].to=b;line[tot2].next=revhead[a];line[tot2].val=c;;revhead[a]=tot++;
}
struct Node{
	int to;
	LL cost;
	bool operator <(const Node&another)const{
		return cost+dist[to]>another.cost+dist[another.to];
	}
	Node(int a,LL c):to(a),cost(c){}
};
inline void dijkstra(int a){
	dist[a]=0;
	priority_queue<P,vector<P>,greater<P> >que;
	que.push(P(0,a));
	while(!que.empty()){
		P p=que.top();
		que.pop();
		if(vis[p.second])continue;
		vis[p.second]=1;
		LL num=p.first;
		for(int i=revhead[p.second];~i;i=line[i].next ){
			if(!vis[line[i].to]&&dist[line[i].to] > num+line[i].val){
				dist[line[i].to]=num+line[i].val;
				que.push(P(dist[line[i].to],line[i].to));
			}
		}
	}
}
inline LL BFS(int a){
	priority_queue<Node>que;
	que.push(Node(a,0));
	while(!que.empty()){
		Node node = que.top();
		que.pop();
		if(node.to==e){
			k--;
			if(k==0)return node.cost;
		}
		for(int i=head[node.to];~i;i=edge[i].next){
			que.push(Node(edge[i].to,node.cost+edge[i].val));
		}
	}
	return -1;
}
signed main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		tot = tot2 = 0;
		memset(dist,INF,sizeof(dist));
		memset(vis,0,sizeof(vis));
		memset(head,-1,sizeof(head));
		memset(revhead,-1,sizeof(revhead));
		for(int i=0;i<m;i++){
			int a,b;
			LL v;
			scanf("%d%d%lld",&a,&b,&v);
			addEdge(a,b,v);
			AddEdge(b,a,v);
		}
		scanf("%d%d%d",&s,&e,&k);
		dijkstra(e);
		if(dist[s]==INF){
			printf("-1\n");continue;
		}
		if(s==e)k++;
		LL ans = BFS(s);
		printf("%lld\n",ans);
	}
	return 0;
}
