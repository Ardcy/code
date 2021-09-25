#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,K;
int ans = 0;
vector<pair<int,int>>P[20];

void dfs(int x,int bud,int liv){
	if(x==n+1){
		if(bud <= K)
		ans = max(ans,liv);
	}
	for(auto p:P[x]){
		dfs(x+1,bud+p.first,liv+p.second);
	}
}
signed main(){
	int t;
	cin >> t;
	for(int uu = 1;uu<=t;uu++){
		for(int i=1;i<=29;i++){
			P[i].clear();
		}
		cin >> n >> K;

		for(int i=1;i<=n;i++){
			P[i].push_back(make_pair(0,0));
			for(int j=1;j<=4;j++){
				int u,v;
				cin >> u >> v;
				P[i].push_back(make_pair(u,v));
			}
		}
		ans = 0;
		dfs(1,0,0);
		cout << "Budget #"<<uu<<": Maximum of "<<ans<<" lives saved."<<endl;
		//cout << ans  << endl;
		cout << endl;
	}
}