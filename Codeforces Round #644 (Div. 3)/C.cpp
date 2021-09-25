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
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int ans = 1e9;
		int cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]%2==0)cnt1++;
		}
		int f = 0;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]==1)f=1;
		}
		if(f==0&&cnt1%2==1){
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	return 0;
}


