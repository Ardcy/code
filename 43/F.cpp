#include<bits/stdc++.h>
using namespace std;
#define maxn 10001
#define int long long
int p[maxn][301],n,m,a,b,ans[maxn],rudu[maxn];
int money=0;
int topsort()
{
       int tot=0,k=0,t;
       while(tot<n)
       {
              t=0;
              for(int i=1;i<=n;++i)
              if(!rudu[i])
              {
                     rudu[i]=99999;
                     tot++;t++;
                     ans[t]=i;
                     money+=100;
              }
              money+=k*t;
              k++;
              if(t==0) return 0;
              for(int i=1;i<=t;++i)
                for(int j=1;j<=p[ans[i]][0];++j)
                {
                    rudu[p[ans[i]][j]]--;
                }
       }
       return 1;
}
signed main(){
	cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
          cin>>a>>b;
          p[b][0]++;
          p[b][p[b][0]]=a;
          rudu[a]++;
    }
    if(topsort()) cout<<money<<endl;
    else printf("Poor Xed");
    return 0;
	
}

