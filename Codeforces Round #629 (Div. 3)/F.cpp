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
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=0;i<=n-k;i++){
		if(a[i]==a[i+k-1]){
			cout<<0;
			return 0;
		}
	}
	int ans = 0, L=0, R=0;
	for(int i=0;i<k-1;i++){
		L+=a[k-1]-a[i];
	}
	for(int i=n-1;i>n-k;i--){
		R+=a[i]-a[n-k];
	}
	for(int i=k;i<n;i++){
		if(a[i]==a[k-1])--L;
		if(a[n-1-i]==a[n-k])--R;
	}
	for(int i=0;i<=(n-1)>>1;i++){
		ans+=a[n-1-i]-a[i];
	}
	ans-=n-k;
	cout<<min(ans,min(L,R));
	return 0;
}
