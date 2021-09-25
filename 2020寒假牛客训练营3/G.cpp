#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const long long mod=1e9+7;
char s[MAXN];
int n,m,x,q;
long long ans;
struct tnode
{
    long long sum,lazy;
    int l,r;
};
struct Segment_Tree
{
    tnode t[4*MAXN];
    void pushdown(int root)
    {
        if(t[root].lazy!=0)
        {
            t[root].sum+=t[root].lazy*(t[root].r-t[root].l+1);
            if(t[root].l!=t[root].r)
            {
                int ch=root<<1;
                t[ch].lazy+=t[root].lazy;
                t[ch+1].lazy+=t[root].lazy;
            }
            t[root].lazy=0;
        }
    }
    void update (int root)
    {
        int ch=root<<1;
        pushdown(ch);
        pushdown(ch+1);
        t[root].sum=t[ch].sum+t[ch+1].sum;
    }
    void build(int l,int r,int root=1)
    {
        t[root].l=l;
        t[root].r=r;
        if(l!=r)
        {
            int mid=(l+r)>>1;
            int ch=root<<1;
            build(l,mid,ch);
            build(mid+1,r,ch+1);
            update(root);
        }
        else t[root].sum=0;
    }
    void change(int l,int r,long long delta,int root=1)
    {
        if(l==t[root].l&&r==t[root].r)
        {
            t[root].lazy+=delta;
            pushdown(root);
            return;
        }
        int mid=(t[root].l+t[root].r)>>1;
        int ch=root<<1;
        if(r<=mid)change(l,r,delta,ch);
        else if(l>mid)change(l,r,delta,ch+1);
        else {change(l,mid,delta,ch);change(mid+1,r,delta,ch+1);}
        update(root);
    }
    long long sum(int l,int r,int root=1)
    {
        pushdown(root);
        if(t[root].l==l&&t[root].r==r)
        {
            return t[root].sum;
        }
        int mid=(t[root].l+t[root].r)>>1;
        int ch=root<<1;
        if(r<=mid)return sum(l,r,ch);
        else if(l>mid)return sum(l,r,ch+1);
        else return sum(l,mid,ch)+sum(mid+1,r,ch+1);
    }
};
Segment_Tree pre,suf;
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    pre.build(1,n);
    suf.build(1,n);
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='1')
        {
            ans=(ans+pre.sum(1,i))%mod;
            if(i!=n)pre.change(i+1,n,1);
            if(i!=1)suf.change(1,i-1,1);
        }
    }
    printf("%lld\n",ans);
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d %d",&q,&x);
        long long pres=pre.sum(1,x);
        long long sufs=suf.sum(x,n);
        if(q==1)
        {
            ans=(ans+pres+sufs)%mod;
            if(x!=n)pre.change(x+1,n,1);
            if(x!=1)suf.change(1,x-1,1);
        }
        else
        {
            ans=((ans-pres-sufs)%mod+mod)%mod;
            if(x!=n)pre.change(x+1,n,-1);
            if(x!=1)suf.change(1,x-1,-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

