#include<bits/stdc++.h>
#define int long long
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

const int MAXN = 2e4+10;
const int INF = 0x3f3f3f3f3f3f;
const int Mod = 1e9+7;
const double eps = 1e-4;
const double Pi = acos(-1.0); 
int n;
struct Node {
	int a, b, index;
	bool operator<(const Node & t) const {
		double da1 = a, db1 = b;
		double da2 = t.a, db2 = t.b;
		if (abs(da1 * db2 - da2 * db1) < eps) {
			return index < t.index;
		}
		return da1 * db2 < da2 * db1;
	}
}node[MAXN];

struct Node2 {
	double a;
	int index;
	bool operator<(const Node2 & t) const {
		if (abs(a - t.a) < eps) {
			return index < t.index;
		}
		return a  < t.a;
	}
}node2[MAXN];

signed main(){
	
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			int fenzi = a + b;
			int fenmu = a + b + c;
			int gcd = __gcd(fenzi, fenmu);
			node[i] = Node{fenzi / gcd, fenmu / gcd, i};
		}
		sort(node + 1, node + 1 + n);
		for (int i = 1; i <= n; i++) {
			if (i != n)
				cout << node[i].index << " ";
			else
				cout << node[i].index << endl; 
		}
	}
	
	return 0;
}



