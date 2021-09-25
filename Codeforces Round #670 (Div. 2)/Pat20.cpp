#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
int pre[N];
int a[N];
signed main(){
	int n;
	cin>>n;
	int sum = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i]+pre[i-1];
		
	}
	sum = pre[n];
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if(u>v)swap(u,v);
		int ans = min(pre[v-1]-pre[u-1],sum+pre[u-1]-pre[v-1]);
		cout<<ans<<endl;
	}
}
