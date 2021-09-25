#include <bits/stdc++.h>
using namespace std;
const int N=128;
const int M=1024;
const int MOD=31011;
int n,m;
int f[N];
struct Edge
{
    int u,v,d;
}e[M];
struct List
{
    int id;
    int nxt;
}ud_list[M];
int hd[M],tt,num;
int cnt[M];
int res=1,sum;
inline int Read(void)
{
    int s=0,f=1; char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for (;isdigit(c);c=getchar()) s=s*10+c-'0';
    return s*f;
}
inline int operator < (Edge ea,Edge eb)
{
    return ea.d<eb.d;
}
inline void InsList(int w,int id)
{
    ud_list[++tt].id=id;
    ud_list[tt].nxt=hd[w];
    hd[w]=tt;
}
int Find(int i)
{
    return f[i]==i?i:Find(f[i]);
}
void DFS(int k,int dep,int goal)
{
    if (dep==goal) {sum++;return;}
    if (!k) return;
    int fu=Find(e[ud_list[k].id].u),fv=Find(e[ud_list[k].id].v);
    if (fu!=fv)
    {
        f[fu]=fv;
        DFS(ud_list[k].nxt,dep+1,goal);
        f[fu]=fu,f[fv]=fv;
    }
    DFS(ud_list[k].nxt,dep,goal);
}
int tmp=0;
int main()
{   
    cin>>n>>m;
    for (int i=1;i<=m;i++) 
	cin>>e[i].u>>e[i].v>>e[i].d;
    sort(e+1,e+m+1);
    for (int i=1;i<=m;i++)
    {
        if (e[i].d!=tmp) num++;
        tmp=e[i].d;
        e[i].d=num;
        InsList(num,i);
    }

    int fu,fv,totc=0;
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=1;i<=m;i++)
    {
        fu=Find(e[i].u),fv=Find(e[i].v);
        if (fu==fv) continue;
        cnt[e[i].d]++,totc++,f[fu]=fv;
    }
    if (totc!=n-1) {printf("0\n");return 0;}
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=1;i<=num;i++)
    {
        sum=0; DFS(hd[i],0,cnt[i]);
        res=res*sum%MOD;
        for (int k=hd[i];k;k=ud_list[k].nxt)
        {
            fu=Find(e[ud_list[k].id].u),fv=Find(e[ud_list[k].id].v);
            if (fu!=fv) f[fu]=fv;
        }
    }
    printf("%d\n",res);
    return 0;
}
