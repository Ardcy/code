#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
#define int long long
int n,m,k;
int cnt=0;
void dfs(int n,int m){
	if(n==0||m==0)return;
	if(n==1&&m!=1){
		for(int i=1;i<m;i++){
			if(cnt<k)cout<<1<<" "<<"R\n",cnt++;
			else return;
		}
		for(int i=1;i<m;i++){
			if(cnt<k)cout<<1<<" "<<"L\n",cnt++;
			else return;
		}
		return; 
	}
	if(m==1&&n!=1){
		for(int i=1;i<n;i++){
			if(cnt<k)cout<<1<<" "<<"D\n",cnt++;
			else return;
		}
		for(int i=1;i<n;i++){
			if(cnt<k)cout<<1<<" "<<"U\n",cnt++;
			else return;
		}
		return;
	}
	
	if(cnt<k)cout<<1<<" "<<"R\n",cnt++;
	else return;
	for(int i=1;i<=m-2;i++){
		if(cnt<k)cout<<1<<" "<<"D\n",cnt++;
		else return;
		if(i==1)dfs(n-2,m-2);
		if(cnt<k)cout<<1<<" "<<"U\n",cnt++;
		else return;
		if(cnt<k)cout<<1<<" "<<"R\n",cnt++;
		else return;
	}
	if(cnt<k)cout<<1<<" "<<"D\n",cnt++;
	else return;
	for(int i=1;i<=n-2;i++){
		if(cnt<k)cout<<1<<" "<<"L\n",cnt++;
		else return;
		if(cnt<k)cout<<1<<" "<<"R\n",cnt++;
		else return;
		if(cnt<k)cout<<1<<" "<<"D\n",cnt++;
		else return;
	}
	if(cnt<k)cout<<1<<" "<<"L\n",cnt++;
	else return;
	for(int i=1;i<=m-2;i++){
		if(cnt<k)cout<<1<<" "<<"U\n",cnt++;
		else return;
		if(cnt<k)cout<<1<<" "<<"D\n",cnt++;
		else return;
		if(cnt<k)cout<<1<<" "<<"L\n",cnt++;
		else return;
	}	
	if(cnt<k)cout<<1<<" "<<"U\n",cnt++;
	else return;
	for(int i=1;i<=n-2;i++){
		if(cnt<k)cout<<1<<" "<<"R\n",cnt++;
		else return;
		if(cnt<k)cout<<1<<" "<<"L\n",cnt++;
		else return;
		if(cnt<k)cout<<1<<" "<<"U\n",cnt++;
		else return;
	}
	for(int i=1;i<=n-1;i++){
		if(cnt<k)cout<<1<<" "<<"D\n",cnt++;
		else return;
	}
	
	for(int i=1;i<=m-1;i++){
		if(cnt<k)cout<<1<<" "<<"R\n",cnt++;
		else return;
	}
	
	for(int i=1;i<=n-1;i++){
		if(cnt<k)cout<<1<<" "<<"U\n",cnt++;
		else return;
	}
	
	for(int i=1;i<=n-1;i++){
		if(cnt<k)cout<<1<<" "<<"L\n",cnt++;
		else return;
	}
}
signed  main(){
	
	cin>>n>>m>>k;
	if(k>(4*n*m-2*n-2*m))cout<<"NO"<<endl;
	else{
		if(k>3000)k=3000;
		cout<<"YES"<<endl; 
		cout<<k<<endl;
		dfs(n,m);
	}
}
