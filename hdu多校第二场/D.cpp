#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>P;
		int ma = 1e9+9;
		for(int i=1,a,b;i<=n;i++){
			cin>>a>>b;
			P.pb(((100+a-1)/a-1)*b);	
		}
		sort(P.begin(),P.end());
		int m = 0;
		double ans = 0;
		for(auto p:P){
			if(p==P[0])m++;
		}
		printf("%.10f\n",1.0-m*0.5/n);
	}
	return 0;
}


