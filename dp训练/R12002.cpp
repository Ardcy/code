#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[200000];
signed main(){
	int n,m;
	cin>>n>>m;
	int mine = 1000000;
	int ans=0,ansindex=m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(i<=m)ans+=b[i];
		if(i==m)mine = ans;
		if(i>m){
			ans-=b[i-m];
			ans+=b[i];
			if(mine>ans)mine=ans,ansindex=i;	
		}
		
	}
	cout<<ansindex+1-m<<endl;
}
