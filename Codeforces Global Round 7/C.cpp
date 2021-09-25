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
const int mod = 998244353;
int rnd(int x){return mrand()%x;}
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
struct node{
	int x,y;
}e[205000];
int b[205000];
bool cmp(node a,node b){
	return a.x>b.x;
}
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>e[i].x;
		e[i].y=i;
	}
	sort(e+1,e+n+1,cmp);
	int ans = 0;
	for(int i=1;i<=k;i++){
		ans += e[i].x;
	}
	cout<<ans<<" ";
	for(int i=1;i<=k;i++){
		b[i]=e[i].y;
	}
	
	sort(b+1,b+k+1);
	int ans1=1;
	b[k+1]=n+1;
	for(int i=1;i<=k-1;i++){
		ans1*=(b[i+1]-b[i]);
		ans1%=mod;
		
	}
	cout<<ans1<<endl;
	return 0;
}
