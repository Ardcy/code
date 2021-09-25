#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%mod;a*=a,a%=mod;b>>=1;}return ans;};

int dp[500000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		
		int a,b,q;
		cin>>a>>b>>q;
		int l,r;
		for(int i=1;i<=a*b;i++){
			if(i%a%b!=i%b%a){
				dp[i]=dp[i-1]+1;
			}
			else{
				dp[i]=dp[i-1];
			}
		}
		
		for(int i=1;i<=q;i++){
			cin>>l>>r;
			
			int ans1=0;
			int ans2=0;
			ans1 = (l-1)/(a*b) * dp[a*b]+ dp[((l-1)%(a*b))];
			ans2 = r/(a*b) * dp[a*b]+ dp[((r)%(a*b))];
			cout<<(ans2-ans1)<<" ";
			
			
		}
		cout<<endl;
	}
	return 0;
}


