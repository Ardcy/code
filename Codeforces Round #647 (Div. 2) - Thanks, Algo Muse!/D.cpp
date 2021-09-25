#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

struct node{
	int x,y;
}e[505000];
bool cmp(node a, node b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
vector<int>P[606000];
int c[505000];
int d[505000];
signed main(){
	int n,m;
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		P[u].pb(v);P[v].pb(u);
	}
	//for(int i=1;i<=n;i++)cin>>d[i];sort(d+1,d+n+1);
	
	for(int i=1;i<=n;i++){
		cin>>e[i].x;e[i].y=i;
	}
	
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++)c[i]=1;
	int f = 1;
	for(int i=1;i<=n;i++){
		if(c[e[i].y]!=e[i].x){
			f=0;break;
		}else{
			for(auto p:P[e[i].y])if(c[p]==e[i].x)c[p]++;
		}
		//for(int i=1;i<=n;i++)cout<<c[i]<<" ";cout<<endl;
	}
	if(f==0)cout<<-1<<endl;
	else {
		for(int i=1;i<=n;i++)cout<<e[i].y<<" ";cout<<endl;
	}
	return 0;
}


