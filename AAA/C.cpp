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

double pi = acos(-1.0);
signed main(){
	int t;

	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		double sq = 0.5;
		n/=2;
		for(int i=1;i<n;i++){
			
			
			double jiao = 90.0/n*i/180*(pi);
			sq+= cos(jiao);
			
		}
		printf("%.10f\n",sq*2);
		
	}
	return 0;
}


