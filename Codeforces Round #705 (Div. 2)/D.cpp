
#include <bits/stdc++.h>


using namespace  std;
typedef long long ll;
const int maxn = 100005;
const ll inf = 0x3f3f3f3f;
typedef long double ld;
#define met(a, b) memset(a, b, sizeof(a))
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
inline ll mul(ll x, ll y, ll mod) {ll res = (x * y - (ll)(ld)(x / mod * y + 1e-8) * mod); return res < 0 ? res + mod : res;}
const double PI = acos(-1.0);
const int mod = 1e9+7;
ll qPow(ll base, ll n) {ll res = 1; while(n) {if(n & 1) res = (res * base) % mod; base = (base * base) % mod; n >>= 1;} return res % mod;}
ll gcd(ll a, ll b) {
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    return b == 0 ? a : gcd(b, a % b);
}
int n, q, a[maxn];

struct NODE{
    int gd, sum, l, r;
} treeNode[maxn * 4];

void pushUp(int root) {
    treeNode[root].gd = gcd(treeNode[root << 1].gd, treeNode[root << 1 | 1].gd);
    treeNode[root].sum = treeNode[root << 1].sum + treeNode[root << 1 | 1].sum;
}

void build(int root, int l, int r) {
    treeNode[root].l = l;
    treeNode[root].r = r;
    if(l == r) {
        treeNode[root].gd = a[l];
        treeNode[root].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid + 1, r);
    pushUp(root);
}

void update(int root, int pos, int x) {
    if(treeNode[root].l == treeNode[root].r) {
        treeNode[root].gd += x;
        treeNode[root].sum += x;
        return;
    }
    int mid = (treeNode[root].l + treeNode[root].r) >> 1;
    if(pos <= mid) update(root << 1, pos, x);
    else update(root << 1 | 1, pos, x);
    pushUp(root);
    //if()
}

int queryGcd(int root, int l, int r) {
    if(l > r) return 0;
    if(treeNode[root].l == l && treeNode[root].r == r) {
        return treeNode[root].gd;
    }
    int mid = (treeNode[root].l + treeNode[root].r) >> 1;
    if(r <= mid) {
        return queryGcd(root << 1, l, r);
    } else if(l > mid) {
        return queryGcd(root << 1 | 1, l, r);
    } else {
        return gcd(queryGcd(root << 1, l, mid), queryGcd(root << 1 | 1, mid + 1, r));
    }
}

int querySum(int root, int l, int r) {
    if(treeNode[root].l == l && treeNode[root].r == r) {
        return treeNode[root].sum;
    }
    int mid = (treeNode[root].l + treeNode[root].r) >> 1;
    if(r <= mid) return querySum(root << 1, l, r);
    else if(l > mid) return querySum(root << 1 | 1, l, r);
    else {
        return querySum(root << 1, l, mid) + querySum(root << 1 | 1, mid + 1, r);
    }
}

int main() {
        cin >> n >> q;
         {
        map<int,int>mp;
        a[0] = 0;
        rep(i, 1, n) {
            scanf("%d", &a[i]);
            mp[i] = a[i];
        }
        per(i, n, 2) {
            a[i] -= a[i - 1];
        }
        build(1, 1, n);
        vector<int>ans;
        while(q--) {
            int x,y;
            scanf("%d%d", &x,&y);
            //cout << (y-1)*mp[x] << endl;
            update(1,x,(y-1)*mp[x]);
            update(1,x+1,(1-y)*mp[x]);
            mp[x] = mp[x]*y;
            // for(int i=1;i<=n;i++){
            //     cout << queryGcd(1,i,i) << endl;
            // }cout << endl;
            ans.push_back(queryGcd(1,1,n));
            //printf("%lld\n", abs(queryGcd(1,1,n)));
            // int com, l, r;
            // scanf("%d%d%d", &com, &l, &r);
            // if(com == 1) {
            //     printf("%lld\n", abs(gcd(queryGcd(1,l+1,r),querySum(1,1,l))));
            // } else {
            //     int x;
            //     scanf("%d", &x);
            //     update(1, l, x);
            //     if(r < n) update(1, r + 1, -x);
            // }
        }

        for(auto p:ans){
            cout << p << endl;
        }
    }
    return 0;
}
