#include<bits/stdc++.h>
using namespace std;
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
const int mod = 1000000007;
int qp(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
int b[505000];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=2*i;j<=n;j+=i){
			b[j]=i;
		}
	}
	sort(b+1,b+n+1);
	for(int i=2;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
