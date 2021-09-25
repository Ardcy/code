#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};
const double pi = acos(-1.0);
double c[1000][3];
double d[1000];
signed main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=1; i<=2*n; i++) {
			cin>>c[i][0]>>c[i][1]>>c[i][2];
		}
		for(int i=1;i<2*n;i++){
			d[i]=sqrt((c[i][0]-c[2*n][0])*(c[i][0]-c[2*n][0])+(c[i][2]-c[2*n][2])*(c[i][2]-c[2*n][2])+(c[i][1]-c[2*n][1])*(c[i][1]-c[2*n][1]));
		}
		sort(d+1,d+2*n);
		
		double ans = pi*d[n-1]/2*(d[n-1]/2)*d[n];
		printf("%.10f\n",ans);
	}
	return 0;
}


