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
int n,m;
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
struct node{
	int x,y;
}e[1005000];
bool cmp(node a,node b){return a.x<b.x;}
signed main(){
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=n;i++){
		e[i].x=read(),e[i].y=read();
	}
	sort(e+1,e+n+1,cmp);
	int ans = m+1;
	int r=-1;
	for(int i=1;i<=n;i++){
		if(e[i].x>r)ans-=(e[i].x-r-1);
		r=max(r,e[i].y); 
	}
	cout<<ans-(m-r)<<endl;
	return 0;
}
