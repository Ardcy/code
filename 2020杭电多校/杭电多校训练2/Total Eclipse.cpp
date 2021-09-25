#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int pre[N],vis[N];
struct node{
	int val,id;
	bool operator < (const node &a){
		return val > a.val;
	}
}a[N];
vector<int>v[N];
int find(int a){
	if(a == pre[a])return a;
	return pre[a] = find(pre[a]);
}
inline int read(){
	int p;
	scanf("%d",&p);
	return p;
}
signed main(){
	int t;
	t = read();
	while(t--){
		int n,m;
		n = read(),m = read();
		for(int i=1;i<=n;i++){
			pre[i] = i;
			vis[i] = 0;
			v[i].clear();
			int x;
			x=read();
			a[i] = {x,i};
		}
		for(int i=1;i<=m;i++){
			int x,y;
			x = read();y = read();
			v[x].push_back(y);
			v[y].push_back(x);
		}
		sort(a+1,a+n+1);
		long long sum = 0;
		for(int i=1;i<=n;i++){
			sum += a[i].val;
			int id = a[i].id;
			for(auto j:v[id]){
				if(!vis[j])continue;
				int u = find(id),v = find(j);
				if(u!=v){
					pre[u] = v;
					sum -= a[i].val;
				}
			}
			vis[id] = 1;
		}
		printf("%lld\n",sum);
	}	
}