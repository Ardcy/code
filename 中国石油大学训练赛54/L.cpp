#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
const int N=105000;
struct edge{
	int next,to;
}e[150000];
int her;
int d[N],h[N];
int cnt = 0;
inline void add(int f,int t){
	e[++cnt].next=h[f];e[cnt].to=t;h[f]=cnt;d[t]++;
}
pair<int,int>P[N];
map<pair<int,int>,int>R;
void dfs(int root,int f,int c){
	for(int i=h[root];~i;i=e[i].next){
		int e1=e[i].to;
		if(e1!=f){
			if(root<e1)
			R[{root,e1}]=c;else R[{e1,root}]=c;
			c+=1;
			c%=her;
			dfs(e1,root,c); 
		}
	}
}
int main(){
	memset(h,-1,sizeof(h));
	int n,root;
	cin>>n;
	int u,v;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		P[i].first=u;P[i].second=v;
	}
	int ans1 = -100000;
	for(int i=1;i<=n;i++){
		if(ans1<d[i])ans1=d[i],root=i;
	}
	printf("%d\n",ans1);
	her=ans1;
	dfs(root,-1,0);
	for(int i=1;i<=n-1;i++)printf("%d\n",R[P[i]]+1);
}
