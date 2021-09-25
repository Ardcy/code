#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define Mod 1000000007
#define int long long
const int Maxn = 203005;
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
            t[root].sum+=t[root].lazy*(t[root].r-t[root].l+1);
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
        t[root].sum=(t[ch].sum+t[ch+1].sum)%Mod;
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
		else return (sum(l,mid,ch)+sum(mid+1,r,ch+1))%Mod;
	}
};
Segment_tree p,p2;
struct no{
	int x,y;
}e[205000];
int q[205000];
int pe[205000];
bool cmp(no a,no b){
	return a.x<b.x;
}
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>e[i].x;
	for(int i=1;i<=n;i++)cin>>e[i].y;
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++)q[i]=e[i].y,pe[i]=e[i].y;
	sort(pe+1,pe+n+1);
	p.build(1,n);
	p2.build(1,n);

	int ans = 0;
	for(int i=1;i<=n;i++){
	    int r = lower_bound(pe+1,pe+n+1,q[i])-pe;
		int hg = 1;
		hg = upper_bound(pe,pe+n+1,q[i])-pe-1;
		cout<<r<<endl;
		ans -= (r-1-p.sum(r,r))*e[i].x;
		ans += (n-hg-p2.sum(r,r))*e[i].x; 
		if(hg>=1)p.change(1,hg,1);
		if(r<=n)p2.change(r,n,1);
	}
	cout<<ans<<endl;
} 
