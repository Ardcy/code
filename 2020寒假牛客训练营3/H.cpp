#include<bits/stdc++.h>
using namespace std;
#define N 100050
int prime[N];
int b[N];
int cnt = 1;
void prim(){
	
	for(int i=2;i<=N;i++){
		if(b[i]==0)prime[cnt++]=i;
		else continue;
		for(int j=2*i;j<N;j+=i){
			b[j] = 1;		
		}
	}
}
int u[N]={0};
int p[N]={0};
int main(){
	int n,m;
	cin>>n>>m;
	prim();
	for(int i=1;i<N;i++){
		if(b[i]!=0){
		}
		else continue;
		for(int j=2*i;j<N;j+=i){
			b[j] +=1;
		}
	}
	for(int i=1;i<=n;i++){
		u[b[i]]++;
	}	
    int op;
	for(int i=1;i<=m;i++){
        cin>>op;
        cout<<u[op]<<endl;}
}
