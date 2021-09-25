#include<bits/stdc++.h>
#include<time.h>
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
using namespace std;
clock_t st = clock();

void outtime(){
	clock_t ed = clock();
	cout<< "Running time is: "<<(double)(ed-st)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
}
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

const int MAXN = 2e5+10;
const int INF = 0x3f3f3f3f3f3f;
const int Mod = 1e9+7;
const double eps = 1e-8;
const double Pi = acos(-1.0); 
int n;
int arr[MAXN];
signed main(){
	n = 1000000;
	double pi = Pi;
	for(int i=1;i<=n;i++){
		pi += 1.1;
	}
	cout << pi << endl;
	outtime();
	return 0;
}
