#include<bits/stdc++.h>
using namespace std;
#define N 50500
#define M 1001000

struct edge{
	int nex,to,w;
	int c; 
}e[M<<2];
int cnt = 0; 
int h[N];
void add(int a,int b,int c,int d){
	cnt++;
	e[cnt].to=c;
	e[cnt].w=d;
	e[cnt].c=a;
	e[cnt].nex=b;
}
int fath[N];
int father(int x){
	if(x!=fath[x])fath[x]=father(fath[x]);
	return fath[x];
}
void unione(int x,int y){
	fath[father(x)]=father(y);
}
bool cmp(edge x,edge y){
	return x.w <y.w;
}
int n,m,need;
int main(){
	cin>>n>>m>>need;
	for(int i=1,a,b,c,d;i<=m;i++){
		cin>>b>>c>>d>>a;
		add(a,b,c,d);
		add(a,c,b,d);	     
	}
	sort(e+1,e+cnt+1,cmp);
	int nt=0;
	double ans;
	for(int i=1;i<=cnt&&nt<=n;i++){
		if(father(e[i].to)!=father(e[i].nex))
			{
				ans+=e[i].w ;
				nt++;
				unione(e[i].to,e[i].nex);
			}
	}
	cout<<ans;
	
}
