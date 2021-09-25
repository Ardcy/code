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

signed main(){
	int n,m,l,r;
	cin>>n>>m>>l>>r;
	if(n*m%2==1){
		cout<<pb(r-l+1,n*m)<<endl;
	}
	else{
		if((r-l+1)%2==0){
			cout<<pb(r-l+1,n*m)*((mod+1)/2)%mod<<endl;
		}
		else{
			cout<<(pb(r-l+1,n*m)+1)*((mod+1)/2)%mod<<endl;
		}
		
	}
}
