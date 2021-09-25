#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,tot,ned;
#define N 100005
int sumv;
int u[100005],v[100005],w[100005],c[100005];
int fa[N];
struct edge{
	int u,v,w,c;
}e[N];
bool operator<(edge a,edge b){
	return a.w==b.w?a.c<b.c:a.w<b.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool check(int x){
	tot = cnt = 0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		e[i].u=u[i],e[i].v=v[i],e[i].w=w[i];
		e[i].c=c[i]; 
		if(!c[i])e[i].w+=x;
	} 
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int p=find(e[i].u),q=find(e[i].v);
		if(p!=q){
			fa[p]=q;
			tot+=e[i].w;
			if(!e[i].c)cnt++;
		}
	}
	return cnt>=ned;
}
int main(){
	cin>>n>>m>>ned;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i]>>c[i];
		u[i]++;
		v[i]++;
	}
	int l=-105,r=105;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,sumv=tot-ned*mid;
		else r=mid-1;
	}
	printf("%d\n",sumv);
}	
