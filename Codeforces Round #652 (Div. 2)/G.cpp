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
int a[2060000];
int pre[2][2060000];
int suf[2][2060000];
signed main(){
	int n;
	cin>>n;
	if(n==1){
		cin>>a[1];
		cout<<a[1]<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i>1)pre[i%2][i]=pre[i%2][i-2]+a[i];
		else pre[i%2][i]=a[i];
	}
	for(int i=n;i>=1;i--){
		suf[i%2][i]=suf[i%2][i+2]+a[i];
	}
	int ans = a[1]+a[n];
	for(int i=3;i<=n-1;i+=2){
		ans+=a[i];
	}
	for(int i=1;i<=n-1;i++){
		cout<<pre[i%2][i]<<" "<<suf[(i+1)%2][i+1]<<endl;
		ans=max(pre[i%2][i]+suf[(i+1)%2][i+1],ans);
	}	
	cout<<ans<<endl;
	return 0;
}


