#include<bits/stdc++.h>
using namespace std;
#define M(x,y) make_pair(x,y)
#define N 2020
#define M1 2000020
int first[N];
struct node{
	int nexte,to;
	double val;
}edge[M1<<2];
int x,y;
double px[N],py[N];
int cnt = 0;
int head[N];
void add(int x,int y,double z){
	cnt++;
	edge[cnt].to = y;
	edge[cnt].val = z;
	edge[cnt].nexte = head[x];
	head[x] = cnt;
}
double ans = 0;
int vis[N],n,m;
double prim(){
	priority_queue<pair<double,int> >Q;
	Q.push(M(0,1));
	int c = 0;
	while(c<n&&!Q.empty()){
		int now = Q.top().second;
		double uy  = Q.top().first;
		Q.pop();
		if(vis[now])continue;
		vis[now]=1;	
		ans += uy;
		c++;
		for(int i=head[now];i;i=edge[i].nexte){
			if(!vis[edge[i].to])
				Q.push(M(-edge[i].val,edge[i].to)); 
		}
	} 
	return -ans;
}
int main(){
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>px[i]>>py[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			double y1 = sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
			add(i,j,y1);
			add(j,i,y1);
		}
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		add(x,y,0);
		add(y,x,0);
	}
	printf("%.2lf\n",prim());
	return 0;
} 
