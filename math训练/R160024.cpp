#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	
	int n;
	cin>>n;
	int u,w=0,m=0;
	for(int i=1;i<=n;i++)cin>>u,m=max(m,u),w+=u;
	if(m>(w/(n-1)+(w%(n-1)>0)))cout<<m<<endl;else cout<<w/(n-1)+(w%(n-1)>0)<<endl;
}
