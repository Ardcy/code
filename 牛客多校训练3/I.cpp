#include<bits/stdc++.h>
using namespace std;
#define int long long
int mp1[600][600];
int mp2[600][600];
const int INF = 1e16;
signed main(){
	int n,m,t,d;
	cin >> n >> m >> t >> d;
	set<int>P;
	for(int i=1;i<=t;i++){
		int k;cin >> k;P.insert(k);
	}P.insert(1);P.insert(n);
	map<int,int>pp;
	int cnt =1;
	for(auto u:P){
		pp[u] = cnt++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp1[i][j] = INF;mp2[i][j] = INF;
		}
		mp1[i][i] =0;mp2[i][i] = 0;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp1[u][v] = mp1[v][u] = w;
		if(w>d)mp1[u][v] = mp1[v][u] = INF;
	}
	for(int k=1;k<=n;k++)  
        for(int f=1;f<=n;f++)  
            for(int t1=1;t1<=n;t1++)  
                mp1[f][t1] = min(mp1[f][t1],mp1[f][k]+mp1[k][t1]);

    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(pp[i]&&pp[j]){
    			if(mp1[i][j] <= d)
    			mp2[pp[i]][pp[j]] = mp1[i][j];
    			else{
    				mp2[pp[i]][pp[j]] = INF;
    			} 
    		} 
    	}
    }
    n = cnt-1;
	for(int k=1;k<=n;k++)  
        for(int f=1;f<=n;f++)  
            for(int t1=1;t1<=n;t1++)  
                mp2[f][t1] = min(mp2[f][t1],mp2[f][k]+mp2[k][t1]);
    if(mp2[1][n]<INF)
    	cout << mp2[1][n] << endl;
	else{
		cout<<"stuck" << endl;
	}
}