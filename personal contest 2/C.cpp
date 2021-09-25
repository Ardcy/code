#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans=0; 
void dfs(int a,int b){
	if(b==0){ans = n;return;}
	if(b==1){
		ans+=a-1;return;
	} 
	ans+=a/b;
	dfs(b,a%b);
}
signed main(){
	cin>>n;
	if(n==1){
		cout<<0<<endl;return 0;
	}
	int an = 1e9;
	for(int i=1;i<n;i++){
		ans = 0;
		dfs(n,i);
		an=min(an,ans);
	}
	cout<<an<<endl;
}
