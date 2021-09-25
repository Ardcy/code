//  kruskal入门题目 已经部分建边 求加边至连通图的边距离最小 
#include<bits/stdc++.h>
#define M 1000050
#define N 5050
using namespace std;
struct node{
	int x,y;
	double dis;
}edge[M<<2];
int fath[N];
int father(int x){
	if(x!=fath[x])fath[x]=father(fath[x]);
	return fath[x]; 
}
void unione(int x,int y){
	fath[father(x)]=father(y);
}
bool cmp(node x,node y){
	return x.dis<y.dis;
}
int n,m;
double px[N],py[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)fath[i]=i;
	for(int i=1;i<=n;i++){
		cin>>px[i]>>py[i];
	}
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		unione(x,y);
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt++;
			edge[cnt].x=i;
			edge[cnt].y=j;
			edge[cnt].dis=sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
		}
	}
	sort(edge+1,edge+cnt+1,cmp);
	double ans=0;
	for(int i=1;i<=cnt;i++){
		if(father(edge[i].x)!=father(edge[i].y)){
			unione(edge[i].x,edge[i].y);
			ans+=edge[i].dis;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
