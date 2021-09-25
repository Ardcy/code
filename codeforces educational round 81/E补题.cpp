#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,p[200005],a[200005],id[200005];
ll minv[800005],val[200005],addv[800005];
void pushup(int rt)
{
    minv[rt]=min(minv[rt<<1],minv[rt<<1|1]);
}
void pushdown(int rt)
{
    if(addv[rt])
    {
        ll t=addv[rt];
        minv[rt<<1]+=t;minv[rt<<1|1]+=t;
        addv[rt<<1]+=t;addv[rt<<1|1]+=t;
        addv[rt]=0;
    }
}
void build(int rt,int l,int r)
{
    int mid=(l+r)>>1;
    if(l==r){minv[rt]=val[l];return;}
    build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void add(int rt,int l,int r,int ql,int qr,ll v)
{
    int mid=(l+r)>>1;
    if(ql<=l&&r<=qr)
    {
        addv[rt]+=v;minv[rt]+=v;
        return;
    }
    pushdown(rt);
    if(ql<=mid)add(rt<<1,l,mid,ql,qr,v);
    if(qr>mid)add(rt<<1|1,mid+1,r,ql,qr,v);
    pushup(rt);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&p[i]),id[p[i]]=i;
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)val[i]=val[i-1]+a[id[i]];
    build(1,0,n);
    ll ans=(ll)1e18;
    for(int i=1;i<n;++i)
    {
        add(1,0,n,0,p[i]-1,a[i]);
        add(1,0,n,p[i],n,-a[i]);
        ans=min(ans,minv[1]);
    }
    cout<<ans<<endl;
}
