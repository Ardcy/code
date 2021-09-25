#include<bits/stdc++.h>
using namespace std;
#define M 2020
#define N 1000010
struct node{
	int x,y;
	double dis;
}edge[N<<2];
int fath[M];
void ini() {
	for(int i=1;i<=M;i++)fath[i]=i;
}
int father(int x){
	if(x!=fath[x])fath[x]=father(fath[x]);
	return fath[x];
}
void unione(int x,int y){
	fath[father(x)]=father(y);
}
double px[M],py[M];
bool cmp(node x,node y){
	return x.dis<y.dis;
}
int n,m;
int main(){
	ini();
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>px[i]>>py[i];
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;unione(x,y);
	}
	int c=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			c++;
			edge[c].x=i;
			edge[c].y=j;
			edge[c].dis=sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
		}
	}
	sort(edge+1,edge+c+1,cmp);
	double ans = 0;
	for(int i=1;i<=c;i++){
		if(father(edge[i].x)!=father(edge[i].y)){
			unione(edge[i].x,edge[i].y);
			ans += edge[i].dis;
		}
	}
	printf("%.2lf\n",ans); 
	return 0;
}
 
