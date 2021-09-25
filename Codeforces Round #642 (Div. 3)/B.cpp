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

int a[100],b[100];
bool cmp(int a2,int b2){
	return a2>b2;
}
	
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		sort(a+1,a+n+1);sort(b+1,b+n+1,cmp);
		int sum=0;
		for(int i=k+1;i<=n;i++){
			sum+=a[i];
		}
		for(int i=1;i<=k;i++){
			sum+=max(a[i],b[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}


