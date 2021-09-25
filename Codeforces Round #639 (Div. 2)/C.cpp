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

int a[305000];
int b[305000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)b[i]=((a[i]+i)%n+n)%n;
		sort(b,b+n);
		int cnt = 0;
		for(int i=1;i<=n;i++)if(b[i]==b[i-1]+1)cnt++;
		//for(int i=1;i<=n;i++);
		if(cnt==n-1){
			cout<<"YES"<<endl;
		}else cout<<"NO"<<endl;
		
	}
	return 0;
}


