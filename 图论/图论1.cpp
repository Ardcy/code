#include<bits/stdc++.h>
using namespace std;
struct node{
	node *next;
	int where;
}*first[10001];

bool b[10001];
inline void Dfs(int now){
	b[now] = true;
	for(node *x = first[now]; x; x = x->next)
		if(!b[x->where])
			Dfs(x->where);	
}
bool b[100001];
inline void dfs(int now){
	b[now] = true;
	for(int x = first[now]; x; x = x->next)
	{
		if(!b[x->where])
		dfs(x->where);
	}
} 
int cnt = 0;
int  
void add(int x, int y){
	cnt++;
	first[cnt]->where = y;
	first[cnt]->next = first[where];
	
}\\\
inline void Bfs(int S){
	int c[1010];
	c[1] = S;
	for(int k = 1, l = 1; l <= k; l++){
		int m = c[l];
		for(node *x = first[m]; x; x = x->next)
			if(!b[x->where])
				{
				b[x->where] = true;
				c[++k] = x->where;}
	}
}
int n,f[100][100];
inline void floyd(){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] = min(f[i][k],f[k][j]);	
}


int spfa(int S, int T)
{
	int c[1001],dist[1001];
	c[1] =  
}
int main(){
	int dist[100] = {0};
	for(int i = 1; i <= 100; i++){
		memset(dist,i,sizeof(dist));
		cout<< dist[1]+1<<endl;			
	}
	cout<<b[1]<<endl;
	
	return 0;
}
