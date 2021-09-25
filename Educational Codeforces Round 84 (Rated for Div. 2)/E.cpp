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
int a[105000];
int b[105000];
int c[105000];
VI P[105000];

signed main(){
	int n;
	a[1]=10;
	b[1]=10;
	c[1]=20;
	for(int i=2;i<=100;i++){
		a[i]=i*pb(10,i)-c[i-1];
		b[i]=b[i-1]+a[i];
		c[i]=c[i-1]+b[i];
	}
	cout<<a[3]<<endl;
}
