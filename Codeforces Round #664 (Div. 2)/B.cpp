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

signed main(){
	int t;
	t=1;
	while(t--){
		int n,m;
		cin>>n>>m;
		int x,y;
		cin>>x>>y;
		cout<<x<<" "<<y<<endl;
		
		cout<<1<<" "<<y<<endl;
		
		for(int i=1;i<=n;i++){
			if(i&1)
			for(int j=1;j<=m;j++){
				if(!((i==x&&j==y )||(i==1&&j==y )) )cout<<i<<" "<<j<<endl;
			}
			else
			for(int j=m;j>=1;j--){
				if(!((i==x&&j==y )||(i==1&&j==y )) )cout<<i<<" "<<j<<endl;
			}
			
		}		
	}
	return 0;
}


