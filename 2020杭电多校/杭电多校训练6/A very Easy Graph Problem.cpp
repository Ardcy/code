#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
const ll mod = 1e9+7;
struct Edge{
	int nxt,to;
	ll w;
}e[N<<1];
int head[N],tot;
void add(int u,int v,ll w){
	e[++tot] = Edge{head[u],v,w};head[u] = tot;
}
int n,m;
int a[N],pre[N];
int find(int x){
	return x == pre[x]?x:pre[x] = find(pre[x]);
}
int maxp
signed main(){
	
}