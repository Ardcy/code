#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<set>
using namespace std;
const int maxn = 500050;
int n,m,vs = 0,cnt = 0,tot = 0,a,b;
int loop[maxn],vis[maxn],f[maxn],Next[maxn],head[maxn],ver[maxn];
void init(){
	vs = 0,cnt = 0;
	for(int i=0;i<=tot;i++){
		loop[i] = 0;
		vis[i] = 0;
		f[i] = 0;
		Next[i] = 0;
		head[i] = 0;
		ver[i] = 0;
	}
	tot = 0;
}
inline void add(int x,int y){
    ver[++tot] = y; Next[tot] = head[x]; head[x] = tot; 
}

inline int get(int x){
    if(f[x] == x) return x;
    return f[x] = get(f[x]);
}


inline void getloop(int x){
    vis[x] = ++vs;
    for(int i = head[x]; i ;i = Next[i]){
        int y = ver[i];
        if(y == f[x]){
            continue;    
        } 
        if(vis[y] != 0){
            if(vis[y] < vis[x]) continue;    
            loop[++cnt] = y; 
            for(; y!= x; y = f[y]){
                loop[++cnt] = f[y];
            }
        }
        else
        {
            f[y] = x,getloop(y);    
        }
    }
    return; 
}


set<int>P;
int ans1 = 0;
int cnt1 = 0;
int ans[200005];
void dfs(int x){
	cnt1++;
	for(int i = head[x];i;i=Next[i]){
		int y = ver[i];
		if(y==f[x])continue;
		f[y] = x;
		if(P.count(y)){
			continue;
		}
		ans[y] = ans[ver[x]] + 1;
		ans1 += ans[y];
		dfs(y);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		init();
		cin >>n;
		m=n;
	    for(int i = 1;i<= m;i++){
	        scanf("%d%d",&a,&b);
	        add(a,b); add(b,a);
	    }
	    for(int i= 1;i <= n;i++) f[i] = i,ans[i] = 0;
	    getloop(1);
	    P.clear();
	    ans1 = 0;
	    for(int i = 1;i <= cnt ;i++){
	        P.insert(loop[i]);
	    }
		for(int i=1;i<=cnt;i++)	
	    {
	    	f[loop[i]]=0;
	    	cnt1 = 0;
			///cout<<"loop = " << loop[i] <<endl;
	    	dfs(loop[i]);

		//	cout<<ans1<<endl;	    	
		}
		cout<<(n*(n-1)-ans1)<<endl; 
	}
    return 0;
}

