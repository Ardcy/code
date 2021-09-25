#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back

vector< vector<int> > v;
vector<int>P[105];
int con = 0;
void dfs(int a,int co,int k,int n){
    if(co==k&&a==n){
    	cout<<con<<endl;
        con++;
        return;
    }
    if(co==k)return;
    for(auto p:P[a]){
    	cout<<p<<" "<<a<<endl;
        dfs(p,co+1,k,n);
    }
}
int numWays(int n, vector<vector<int>>& relation, int k) {
    int u,v;
    int l = relation.size();
    for(int i=0;i<l;i++){
        u=relation[i][0];v=relation[i][1];
        P[u].push_back(v);
    }
    cout<<P[0][0]<<endl;
    dfs(0,0,k,n-1);
    return con;
    
}
signed main(){
	int n=5,k=3;
	
	v.pb({0,2});
	v.pb({2,1});
	v.pb({3,4});
	v.pb({2,3});
	v.pb({1,4});
	v.pb({2,0});
	v.pb({0,4});
	
	int mu = numWays(n,v,k);
	cout<<mu<<endl;
	return 0;
}


