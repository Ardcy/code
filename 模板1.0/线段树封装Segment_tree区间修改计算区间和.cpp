#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define Mod 1000000007
#define int long long
const int Maxn = 100005;
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
Segment_tree p;
signed main(){

	return 0;
}
