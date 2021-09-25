#include<bits/stdc++.h>
#define double long double
#define sf(n) scanf("%lld",&n)
#define sff(a,b) scanf("%lld%lld",&a,&b)
#define sfff(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define debug printf("Here\n");
#define out(x) printf("%lld\n",x)
#define out2(x,y) cout << x <<" " << y << endl
#define out3(x,y,z) cout << x << " " << y << " " << z << endl
#define pb push_back
#define fi first
#define se second 
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size)
using namespace std;

inline int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s *10 + ch - '0',ch = getchar();
	}
	return s*w;
}
void yes(){cout << "YES" <<endl;
}
void no(){cout <<" NO"<<endl;}

const int MAXN = 150000+10;
const int MAXM = MAXN << 6;
const int Mod = 1e9+7;
const double eps = 1e-8;
const double Pi = acos(-1.0); 

int n, q, tot;

int a[MAXN];

int T[MAXN], lson[MAXM], rson[MAXM], c[MAXM], ll[MAXM], rr[MAXM];

int minV[MAXN][50], maxV[MAXN][50];

int build(int l, int r) {
	int root = tot++;
	c[root] = 0;
	ll[root] = l, rr[root] = r;
	if (l != r) {
		int mid = (l + r) >> 1;
		lson[root] = build(l, mid);
		rson[root] = build(mid + 1, r);
	}
	return root;
}

int update(int root, int pos, int val) {
	int newroot = tot++, tmp = newroot;
	c[newroot] = c[root] + val;
	ll[newroot] = ll[root], rr[newroot] = rr[root];
	int l = 1, r = MAXN - 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (pos <= mid) {
			lson[newroot] = tot++;
			rson[newroot] = rson[root];
			newroot = lson[newroot];
			root = lson[root];
			r = mid;
		}
		else {
			rson[newroot] = tot++;
			lson[newroot] = lson[root];
			newroot = rson[newroot];
			root = rson[root];
			l = mid + 1;
		}
		c[newroot] = c[root] + val;
		ll[newroot] = ll[root], rr[newroot] = rr[root];
	}
	return tmp;
}

//int query(int root, int k) {
//	if (ll[root] >= k) {
//		return c[root];
//	}
//	else if (rr[root] < k) {
//		return 0;
//	}
//	else {
//		return query(lson[root], k) + query(rson[root], k);
//	}
//}

int query(int lroot, int rroot, int k) {
	if (ll[lroot] >= k) {
		return c[rroot] - c[lroot];
	}
	else if (rr[lroot] < k) {
		return 0;
	}
	else {
		return query(lson[lroot], lson[rroot], k) + query(rson[lroot], rson[rroot], k);
	}
}


signed main(){
	while (~scanf("%d%d", &n, &q)) {
		tot = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			minV[i][0] = maxV[i][0] = a[i];
		}
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 1; i + (1 << j) <= n + 1; i++) {
				minV[i][j] = min(minV[i][j - 1], minV[i + (1 << (j - 1))][j - 1]);
				maxV[i][j] = max(maxV[i][j - 1], maxV[i + (1 << (j - 1))][j - 1]);
			}
		}
		T[0] = build(1, MAXN - 1);
		for (int i = 1; i <= n; i++) {
			T[i] = update(T[i - 1], a[i], 1);
		}
		while (q--) {
			int query_l = read(), query_r = read();
			int len = query_r - query_l + 1;
			int k = log2(len);
			int l = min(len, min(minV[query_l][k], minV[query_r - (1 << k) + 1][k]));
			int r = min(len, max(maxV[query_l][k], maxV[query_r - (1 << k) + 1][k]));
			int ans = 0;
			while (l <= r) {
				int mid = (l + r) >> 1;
//				int cnt1 = query(T[query_l - 1], mid), cnt2 = query(T[query_r], mid);
				int cnt = query(T[query_l - 1], T[query_r], mid);
				if (cnt >= mid) {
					ans = max(ans, mid);
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
