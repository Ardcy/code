#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
const int N = 200500;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
int inv[N],fac[N],rev[N];
void init(int n){
	fac[0]=1;rev[n]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1;i<n;i++)inv[i]=(rev[i]*fac[i-1]%mod)%mod;
}
int a[N];
signed main(){
	int n;
	cin>>n;
	int p = 1;
	for(int i=1;i<=n;i++)a[i]=0;
	for(int i=2;i<=n;i++){
		int x1,x2;
		cout<<"? ";
		cout<<p<<" "<<i<<endl;
		fflush(stdout);
		
		cin>>x1;
		cout<<"? ";
		cout<<i<<" "<<p<<endl;
		fflush(stdout);
		
		cin>>x2;
		
		if(x1>x2){
			a[p]=x1;
			p = i;
		}else{
			a[i]=x2;
		}
		
	}
	cout<<"!"<<" ";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
	fflush(stdout);
	return 0;
}


