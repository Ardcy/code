#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> VI;
int ans1 = 0;
VI P[3000];
void dfs(int a,int f,int d,int y){
	if(d<=y)ans1++;
	if(d==y)return;
	for(auto p:P[a]){
		if(p==f)continue;
		dfs(p,a,d+1,y);
	}
}
int a[3000],b[3000];
signed main(){
	int n,k;
	cin>>n>>k;
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		a[i]=u,b[i]=v;
		P[u].push_back(v);
		P[v].push_back(u);
	}
	int ans = 0;
	if(k%2==0){
		for(int i=1;i<=n;i++){
			ans1=0;
			dfs(i,-1,0,k/2);
			ans=max(ans,ans1);
		}	
	}
	else{
		for(int i=1;i<n;i++){
			ans1=0;
			dfs(a[i],b[i],0,k/2);
		//	cout<<"1:"<<ans1<<endl;
			dfs(b[i],a[i],0,k/2);
			ans=max(ans,ans1);
		//	cout<<"2:"<<ans1<<endl;
		}
		
	} 
	cout<<n-ans<<endl;
	return 0;
	
}
/*
6 3
6 1
5 1
1 2
2 3
2 4
*/
