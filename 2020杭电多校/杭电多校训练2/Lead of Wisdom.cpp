#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a[5];
}e[100];
vector<node>p[100];

int res = 0;
int nxt[100];
int cnt = 0;
void dfs(int idx,int ed,int a,int b,int c,int d){
	if(idx <= ed && p[idx].size()==0){
		idx = nxt[idx];	
	}
	if(idx == ed+1){
		cnt++;
		long long  res1 = ((long long)a*b*c*d);
		res = max(res1,res);
		return;
	}
	{
		for(int i=0;i<p[idx].size();i++){
			dfs(idx+1,ed,a+p[idx][i].a[1],b+p[idx][i].a[2],c+p[idx][i].a[3],d+p[idx][i].a[4]);
		}
	}
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		res = 0;
		int n,k;
		cnt = 0;
		cin >> n  >> k;

		for(int i=1;i<=k;i++){
			p[i].clear();
		}
		for(int i=1,idx;i<=n;i++){
			cin >> idx;
			node y;
			for(int j=1;j<=4;j++){
				cin >> y.a[j];
			}
			p[idx].push_back(y);
		}
		nxt[k] = k+1;
		for(int i=k;i>=1;i--){
			if(p[i].size()){
				nxt[i-1] = i; 
			}else{
				nxt[i-1] = nxt[i];
			}
		}
		dfs(1,k,100,100,100,100);
		
		cout << res << endl;
	}
}