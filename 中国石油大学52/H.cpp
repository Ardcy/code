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
VI P[10];
map<PII,int>Pe;
set<int>Pr;

int a[100000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+2*n+1);
	int ans = 0;
	for(int i=1;i<=2*n;i+=2){
		ans+=a[i];
	}
	cout<<ans<<endl;
}
