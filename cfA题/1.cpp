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
int a[40]; 
signed main(){
	for(int i=1;i<=4;i++)cin>>a[i];
	int f=1;
	int sum=0;
	for(int i=1;i<=4;i++)sum+=a[i];
	for(int i=1;i<=4;i++)for(int j=i+1;j<=4;j++)if(a[i]+a[j]+a[i]+a[j]==sum)f=0; 
	for(int i=1;i<=4;i++)if(a[i]+a[i]==sum)f=0;
	if(f==0)cout<<"YES"<<endl;else cout<<"NO"<<endl;
	return 0;
}
