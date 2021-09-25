#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
vector<int>P[205000];
int dep[205000]={0};
int vis[205000]={0};
void dfs(int p,int pre){
	if(p!=1)dep[p]=dep[pre]+1;
	//cout<<p<<" "<<dep[p]<<endl;
	for(auto q:P[p]){
		if(q==pre)continue;
		else dfs(q,p);
	}
}

int con[205000];

struct node{
	int x,y,z,k;
	
}e[205000];
bool cmp(node a,node b){
	if(a.y==b.y){
		return a.k>b.k;
	}
	return a.y<b.y;
}
void dfs2(int p,int pre){
//	cout<<" "<<p<<" "<<P[p].size()<<endl;

		if(e[p].z==1)con[p]=con[pre]+1;
		else con[p]=con[pre];	

	//cout<<p<<" "<<dep[p]<<endl;
	for(auto q:P[p]){
		if(q==pre)continue;
		else dfs2(q,p);
	}
}
int cone[205000];
void dfs3(int p,int pre){
//	cout<<" "<<p<<" "<<P[p].size()<<endl;

	cone[p]=cone[pre]+1;
	
	//cout<<p<<" "<<dep[p]<<endl;
	for(auto q:P[p]){
		if(q==pre)continue;
		else dfs3(q,p);
	}
}
bool cmp2(node a,node b){
	return a.x<b.x;
}
signed main(){
	int n;
	cin>>n;
	int k;
	cin>>k;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		P[u].pb(v);P[v].pb(u);
	}
	//cout<<P[2].size()<<endl;
	dep[1]=0;
	dfs(1,0);
	for(int i=1;i<=n;i++){
		e[i].x=i,e[i].y=dep[i];
	}
	for(int i=1;i<=n;i++){
		e[i].k=cone[k];
	}
	dfs3(1,0);
	
	

	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n-k;i++){
		e[i].z=1;
	}
	sort(e+1,e+n+1,cmp2);
	for(int i=1;i<=n;i++){
		cout<<e[i].z<<endl;
	}
	dfs2(1,0);
	
	int sum = 0;
	//for(int i=1)
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<con[i]<<endl;
		if(e[e[i].x].z==1){
			sum+=con[i];
		}
	}
	cout<<sum<<endl;
	return 0;
}


