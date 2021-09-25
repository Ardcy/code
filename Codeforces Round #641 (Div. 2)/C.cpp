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

int a[205000];
int b[205000];
int c[205000];
signed main(){
	int t;
	t=1;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int p = a[n],q=a[n];
		b[n]=a[n];
		for(int i=n-1;i>=1;i--)b[i]=__gcd(a[i],p),p=b[i],c[i]=q*a[i]/__gcd(a[i],q),q=c[i];
		int ans =a[1]*b[2]/b[1];
		for(int i=2;i<=n-1;i++){
			ans=__gcd(a[i]*b[i+1]/b[i],ans);
			//cout<<ans<<endl; 
		}
		cout<<ans<<endl;

	}
	return 0;
}


