#include<bits/stdc++.h>
#define sf(n) scanf("%lld",&n)
#define sff(a,b) scanf("%lld%lld",&a,&b)
#define sfff(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define debug printf("Here\n")
#define out(x) cout << x << endl
#define out2(x,y) cout << x << " " << y << endl
#define out3(x,y,z) cout << x << " " << y <<" " << z << endl
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
using namespace std;

inline int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){
		if(ch=='-')w = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <='9'){
		s = s*10+ch - '0',ch = getchar();
	}
	return s*w;
} 
void yes(){cout << "YES" << endl;}
void no(){cout <<"NO" << endl;}

const int  MAXN = 3e5 + 10;
const int INF = 0x3f3f3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-9;
const double PI = acos(-1.0);

int n, m, k, ans;

int arr[MAXN];

int tot, lisan[MAXN];

void lisan_add(int x) {
	lisan[tot++] = x;
}

void lisan_sort() {
	sort(lisan + 1, lisan + 1 + tot);
	tot = unique(lisan + 1, lisan + 1 + tot) - lisan;
}

int lisan_id(int x) {
	return lower_bound(lisan + 1, lisan + 1 + tot, x) - lisan;
}

int c[MAXN];

int lowbit(int x) {
	return x & -x;
}

int BIT_ask(int x) {
	int ans = 0;
	for (; x; x -= lowbit(x)) ans += c[x];
	return ans;
}

void BIT_add(int x, int y) {
	for (; x <= tot; x += lowbit(x)) c[x] += y;
}

int BIT_calc(int l, int r) {
	if (l == 0) return BIT_ask(r);
	return BIT_ask(r) - BIT_ask(l - 1);
}

int t, L[MAXN], R[MAXN];

struct Query {
	int l, r, idx, ans;
} query[MAXN];

bool cmp_left(Query &a, Query &b) {
	if(a.l/t == b.l/t){
		if((a.l/t)&1){
			return a.r < b.r;
		}else{
			return a.r > b.r;
		}
	}
	return a.l/t < b.l/t;
}

bool cmp_right(Query &a, Query &b) {
	return a.r < b.r;
}

bool cmp_idx(Query &a, Query &b) {
	return a.idx < b.idx;
}

void add(int l, int r) {
//	cout << "add: " << l << " " << r << endl;
	for (int i = l; i <= r; i++) {
		int now = arr[i];
		int ll = lisan_id(now - k), rr = lisan_id(now + k);
		int num = BIT_calc(ll, rr);
		ans += num;
		BIT_add(lisan_id(now), 1);
	}
//	cout << ans << endl;
}

void del(int l, int r) {
//	cout << "del: " << l << " " << r << endl;
	for (int i = l; i <= r; i++) {
		int now = arr[i];
		BIT_add(lisan_id(now), -1);
		int ll = lisan_id(now - k), rr = lisan_id(now + k);
		int num = BIT_calc(ll, rr);
		ans -= num;
	}
//	cout << ans << endl;
}

signed main(){
	tot = 1;
	sfff(n, m, k);
	for (int i = 1; i <= n; i++) {
		arr[i] = read();
		lisan_add(arr[i]);
		lisan_add(arr[i] + k);
		lisan_add(arr[i] - k);
	}
	lisan_sort();
	for (int i = 1; i <= m; i++) {
		sff(query[i].l, query[i].r);
		query[i].idx = i;
	}
	t = sqrt(m);
	sort(query + 1, query + 1 + m, cmp_left);

	
	
//	for (int i = 1; i <= t; i++) {
//		L[i] = R[i - 1] + 1;
//		R[i] = i * t;
//	}
//	if (R[t] < m) t++, L[t] = R[t - 1] + 1, R[t] = m;
//	for (int i = 1; i <= t; i++) {
//		sort(query + L[i], query + R[i] + 1, cmp_right);
//	}
	ans = 0;
	for (int i = 1; i <= m; i++) {	
		if(i==1){
			add(query[i].l, query[i].r);
			query[i].ans = ans;
			continue;	
		}
		int j = i;

		if (query[j].r >= query[j - 1].r) {
			add(query[j - 1].r+1, query[j].r);
		}
		else {
			del(query[j].r+1, query[j - 1].r);
		}
		if (query[j].l >= query[j - 1].l) {
			del(query[j - 1].l, query[j].l - 1);
		}
		else {
			add(query[j].l, query[j - 1].l - 1);
		}
		query[j].ans = ans;
	
	}
	sort(query, query + m + 1, cmp_idx);
	for (int i = 1; i <= m; i++) {
		printf("%d\n", query[i].ans);
	}
}
