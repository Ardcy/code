#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
vector<int>P[105000];

int a[105000];
signed main(){	
	int n;
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		P[u].pb(v);P[v].pb(u);
	}	
	for(int i=1;i<=n;i++){
		for(auto p:P[i]){
			a[i]+=P[p].size()-1;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}
}
