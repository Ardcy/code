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

int P[550];
int a[300],b[300];
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	
	int p = 1000;
	for(int i=0;i<=511;i++){
		int f = 1;
		for(int j=1;j<=n;j++){
			
			int f1 = 0;
			for(int k=1;k<=m;k++){
				if(((a[j]&b[k])|i)==i)
					f1 = 1;	
			}
			if(f1==0)f=0;
		}
		if(f==1)p=min(p,i);
		
	}
	cout<<p<<endl;
	return 0;
}


