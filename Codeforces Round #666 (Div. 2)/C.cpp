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
int n;
void solve1(){
	cout<<1<<" "<<1<<endl;
	cout<<a[1]<<endl;
	cout<<1<<" "<<1<<endl;
	cout<<0<<endl;
	cout<<1<<" "<<1<<endl;cout<<0<<endl;
}
void solve2(){
	vector<int>ans;
	
	cout<<1<<" "<<1<<endl;
	cout<<n-a[1]<<endl;
	ans.pb(-1);
	
	cout<<2<<" "<<n<<endl;
	for(int i=2;i<=n;i++){
		cout<<a[i]*(n-1)<<" ";
		ans.pb(-a[i]);
	}cout<<endl;
	cout<<1<<" "<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<ans[i]*(n)<<" ";
	}cout<<endl;
}

signed main(){
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n==1){
		solve1();
	}
	else {
		solve2();
	}
	return 0;
}


