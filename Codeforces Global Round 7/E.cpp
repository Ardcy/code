#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const int mod = 1000000007;
int rnd(int x){return mrand()%x;}
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int p[305000];
int q[305000];
#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define Mod 1000000007
#define int long long
//#define lson l, m, rt<<1
//#define rson m+1, r, (rt<<1)|1
//
//int tree[311111<<2];
//int posn[311111<<2];
//void pushup(int rt)
//{
//    if (tree[rt<<1] > tree[rt<<1|1])
//    {
//        tree[rt] = tree[rt<<1];
//        posn[rt] = posn[rt<<1];
//    }
//    else
//    {
//        tree[rt] = tree[rt<<1|1];
//        posn[rt] = posn[rt<<1|1];
//    }
//}
//void build(int l, int r, int rt)
//{
//    if (l == r)
//    {
//        tree[rt]=0 ;
//        posn[rt] = l;
//    }
//    else
//    {
//        int m = (l + r) >> 1;
//        build(lson);
//        build(rson);
//        pushup(rt);
//    }
//}
//void update(int p, int val, int l, int r, int rt)
//{
//    if (l == r)
//    {
//        tree[rt] = val;
//    }
//    else
//    {
//        int m = (l + r) >> 1;
//        if (p <= m)
//        {
//            update(p, val, lson);
//        }
//        else
//        {
//            update(p, val, rson);
//        }
//        pushup(rt);
//    }
//}
//int query(int L, int R, int l, int r, int rt, int *pos)
//{
//    if (L <= l && r <= R)
//    {
//        *pos = posn[rt];
//        return tree[rt];
//    }
//    else
//    {
//        int m = (l + r) >> 1;
//        int ret1 = INT_MIN;
//        int ret2 = INT_MIN;
//        int pa, pb;
//        int *pos1 = &pa;
//        int *pos2 = &pb;
//        if (L <= m)
//        {
//            ret1 = query(L, R,  lson, pos1);
//        }
//        if (R > m)
//        {
//            ret2 = query(L, R, rson, pos2);
//        }
//        if (ret1 > ret2)
//        {
//            *pos = pa;
//        }
//        else
//        {
//            *pos = pb;
//            ret1 = ret2;
//        }
//        return ret1;
//    }
//}
const int Maxn = 300005;
struct tnode{
	int sum,lazy;
	int l,r;
};
struct Segment_tree{
	tnode t[4*Maxn];
    void pushdown(int root)
    {
        if(t[root].lazy!=0)
        {
            t[root].sum+=t[root].lazy;
            t[root].sum%=Mod;
            if(t[root].l!=t[root].r)
            {
                int ch=root<<1;
                t[ch].lazy+=t[root].lazy;
                t[ch].lazy%=Mod;
                t[ch+1].lazy+=t[root].lazy;
                t[ch+1].lazy%=Mod;
            }
            t[root].lazy=0;
        }
    }
    void update (int root)
    {
        int ch=root<<1;
        pushdown(ch);
        pushdown(ch+1);
        t[root].sum=max(t[ch].sum,t[ch+1].sum);
    }
	void build(int l,int r,int root=1){
		t[root].l=l;
		t[root].r=r;
		if(l!=r){
			int mid=(l+r)>>1;
			int ch=root<<1;
			build(l,mid,ch);
			build(mid+1,r,ch+1);
			update(root);
		}
		else t[root].sum=0;
	}
	void change(int l,int r,int delta,int root=1){
		if(l==t[root].l&&r==t[root].r){
			t[root].lazy+=delta;
			t[root].lazy%=Mod;
			pushdown(root);
			return;
		}
		int mid=(t[root].l+t[root].r)>>1;
		int ch=root<<1;
		if(r<=mid)change(l,r,delta,ch);
		else if(l>mid)change(l,r,delta,ch+1);
		else {
			change(l,mid,delta,ch);
			change(mid+1,r,delta,ch+1);
		}
		update(root);
	}
	int sum(int l,int r,int root=1){
		pushdown(root);
		if(t[root].l==l&&t[root].r==r){
			return t[root].sum;
		}
		int mid = (t[root].l+t[root].r)>>1;
		int ch = root<<1;
		if(r<=mid)return sum(l,r,ch);
		else if(l>mid)return sum(l,r,ch+1);
		else return max(sum(l,mid,ch),sum(mid+1,r,ch+1));
	}
};
Segment_tree P;
int w[305000];
signed main(){
	int n;
	cin>>n;

	for(int i=1;i<=n;i++)cin>>p[i],w[p[i]]=i;
	
	P.build(1,n);
	for(int i=1;i<=n;i++)cin>>q[i];
	int ans = n;
	P.change(1,w[ans],1);
	for(int i=1;i<=n;i++){
		int pos;
		
		int nd = P.sum(1,n);
		while(nd<=0){
			P.change(1,w[--ans],1);nd=P.sum(1,n);
//			cout<<"nd="<<nd<<endl;
		}
		cout<<ans<<" ";
//		cout<<"ans="<<ans<<endl; 
		P.change(1,q[i],-1);
	}
	return 0;
}
