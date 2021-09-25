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

int a[105000];
int b[105000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i],b[i]=1;
		
		//sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)for(int j=2*i;j<=n;j+=i)if(a[j]>=a[i])b[j]=b[i]+1;
		int ans = 1;
		for(int i=1;i<=n;i++)ans=max(ans,b[i]);
		cout<<ans<<endl;
		
	}
	return 0;
}


