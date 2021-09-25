#include<bits/stdc++.h>
using namespace std;
#define N 3030
#define M1 1000010
#define M(x,y) make_pair(x,y)
struct node{
	double dis;
	int next,to;
}e[M1<<2];
int cnt = 0,head[N];
void add(int x,int y,double dis){
	cnt++;
	e[cnt].to=y;
	e[cnt].dis=dis;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int num = 0,n,m;
double ans = 0;
int v[N];
double prim(){
	priority_queue<pair<double,int> >Q;
	Q.push(M(0,1));
	while(!Q.empty()&&num<n){
		int a = Q.top().second;
		double b = Q.top().first;
		Q.pop();
		if(v[a])continue;
		ans += b;
		v[a]=1;
		num++;
		for(int i = head[a];i;i=e[i].next){
			if(!v[e[i].to])
				Q.push(M(-e[i].dis,e[i].to));
		}
	}
	return -ans;
}
double px[N],py[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>px[i]>>py[i];		
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			double dis = sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
			add(i,j,dis);
			add(j,i,dis);
		}
	}
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		add(x,y,0);
		add(y,x,0);
	}
	
	printf("%.2lf\n",prim());
} 
