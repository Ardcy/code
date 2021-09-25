#include<bits/stdc++.h>
#define int long long
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

const int  MAXN = 2e5+10;
const int INF = 0x3f3f3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-9;
const double PI = acos(-1.0);

int n;
int arr[MAXN], dp[MAXN];


int qp(int a,int b)
{
	int ans = 1;
	while(b){
		cout << b << endl;
		if(b&1)ans*=a,ans%=INF;
		a*=a;a%=INF;
		b>>=1;
	}return ans;
}
signed main(){
	
//	cout << qp(2,4) << endl;
	int k, n, m, p;
	while(cin >> k) {
		cin >> m >> n >> p;
		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
		}
		sort(arr + 1, arr + 1 + k);
		int N = 0, base = n;

		N = n * (qp(n, m - 1) - 1);
		//cout << N << endl;
		if(n==1) N = m-1; 
		else N /= (n - 1); 
		//cout << N << endl; 
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			dp[i] = dp[(i - 1) / n] + arr[i];
			dp[i] %= p;
			ans += dp[i];
			ans %= p;
		}
		cout << ans << endl;
		break;
	}
	

}



