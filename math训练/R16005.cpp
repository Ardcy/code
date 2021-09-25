#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N_ = 1050;
int N;
int P[N_];
char S[N_];
int g[N_];
int f(int x){
	if(x==g[x])return x;
	return g[x]=f(g[x]);
}
int m(int a,int b){
	g[f(a)]=f(b);
}
vector<int>pos[N_];
int cnt[N_];
signed main(){
	cin>>N;
	for(int i=1;i<=N;i++)g[i]=i;
	for(int i=1;i<=N;i++)cin>>P[i];
	for(int i=1;i<=N;i++){
		scanf("%s",S+1);
		for(int j=1;j<=N;j++){
			if(S[j]=='1')m(i,j);
		}
	}
	for(int i=1;i<=N;i++)pos[f(i)].push_back(P[i]);
	for(int i=1;i<=N;i++)sort(pos[i].begin(),pos[i].end());
	for(int i=1;i<=N;i++){
		int g=f(i);
		printf("%d ", pos[g][cnt[g]++]);
	}
	return 0;
}
