#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> P[105000];
double ans1 = 0;
void dfs(int u,int from,double pe,int deep){
	int n=P[u].size()-1;
	if(u==1)n++;
//	cout<<"n="<<n<<" pe="<<pe<<endl;
	if(n==0){
		ans1 += pe*deep;
//		cout<<pe<<" ----- "<<deep<<endl;
		return;
	}
	for(auto p:P[u]){
		if(p==from)continue;
		dfs(p,u,pe*1.0/n,deep+1);
		
	}	
}
signed main(){
	int n;
	cin>>n;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		P[u].push_back(v);P[v].push_back(u);
	}
	double ans = 0;
	dfs(1,0,1.0,0);
//	cout<<ans1<<endl;
	printf("%.14f\n",ans1);
	return 0;
}
