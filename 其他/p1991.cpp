#include<bits/stdc++.h>
using namespace std;
#define N 5050
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
double H[N];
void prim(){
	priority_queue<pair<double,int> >Q;
	double ans = 0;
	Q.push(M(0,4));
	while(!Q.empty()&&num<m){
		int a = Q.top().second;
		double b = Q.top().first;
		Q.pop();
		if(v[a])continue;
		H[num]=-b;
		v[a]=1;
		num++;
		for(int i = head[a];i;i=e[i].next){
			if(!v[e[i].to])
				Q.push(M(-e[i].dis,e[i].to));
		}
	}
}
double px[N],py[N];
int main(){
	cin>>n>>m;
	int x,y;
	int z;
	for(int i=1;i<=m;i++){
		cin>>px[i]>>py[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			double dis = sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
			add(i,j,dis);
			add(j,i,dis);
		}
	}
	prim();
	sort(H,H+num);
	printf("%.2lf\n",H[m-n]);
	return 0;
} 
