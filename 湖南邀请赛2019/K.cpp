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

const int MAXN = 2e5+10;
const int INF = 0x3f3f3f3f3f3f;
const int Mod = 1e9+7;
const double eps = 1e-8;
const double Pi = acos(-1.0); 
int n;
int arr[MAXN];
signed main(){
	int l1,l2,r1,r2;
	while(cin >> l1 >> r1 >> l2 >> r2){
		int a1,a2,b1,b2,c1,c2;
		a1 = r1/2018 - (l1-1)/2018;
		b1 = r1/2 - (l1-1)/2 - a1;
		c1 = r1/1009 - (l1-1)/1009 - a1;
		a2 = r2/2018 - (l2-1)/2018;
		b2 = r2/2 - (l2-1)/2 - a2;
		c2 = r2/1009 - (l2-1)/1009 - a2;
		int ans = a1*(r2-l2+1) + b1 * (a2+c2) + c1 * (a2+b2) + (r1-l1+1 - b1 - a1 - c1)*a2;
		cout << ans << endl; 
	}
	return 0;
}
