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

signed main(){
	int n;
	cin>>n;
	int a,b,c,d,e,f;
	a=n+pb(2,17);
	b=n;
	c=0;
	d=pb(2,17);
	e=a;
	f=n;
	cout<<2<<" 3"<<endl;
	cout<<a<<" "<<b<<" "<<c<<endl;
	cout<<d<<" "<<e<<" "<<f<<endl;
	return 0;
}
