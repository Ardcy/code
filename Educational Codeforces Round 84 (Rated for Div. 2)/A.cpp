#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
typedef vector<int> VI;
typedef pair<int,int> PII;
const int mod = 1000000007;
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int a[100000];
int b[100000];
signed main(){
	int t,n;
	t=1;
	cin>>t;
	int k;
	while(t--){
		cin>>n>>k;
		n-=k*k;
		if(n>=0&&n%2==0)cout<<"YES"<<endl;else cout<<"NO"<<endl;
		
	}
}
