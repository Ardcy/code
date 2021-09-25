#include<bits/stdc++.h>
using namespace std;

const int N = 200500;
int prime[N],vis[N],mip[N];
void init(){
	int cnt = 0;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			vis[i] = 1;
			prime[cnt++] = i;
			mip[i] = i;
		}
		for(int j=0;j<cnt&&prime[j]*i<N;j++){
			vis[i*prime[j]]=1;
			mip[i*prime[j]] = prime[j]; 
			if(i%prime[j]==0)break;
		}
	}
}


void g(int n,int j){
	set<int>st;
	for(int i=0;;i++){
		if(prime[i]<=n)st.insert(prime[i]);
		else break;
	}
	for(int i=2;i<=n;i++){
		if(st.count(i)||mip[i]>prime[j]){
			cout << i << " ";
		}
	}cout << endl;
}
signed main(){
	init();
	for(int i=5;i<=20;i++){
		cout << i  <<" " << mip[i]<< endl;
	}
	int n,j;
	while(cin >> n >> j){
		g(n,j);
	}	
}
