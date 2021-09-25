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
int a[10];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int c1=0, c2=0;
		for(int i=1;i<=4;i++){
			cin>>a[i];
			if(a[i]&1)c1++;
			if(a[i]==0&&i!=4)c2++;
		}
		if(c1==4){
			cout<<"YES"<<endl;
		}
		else if(c1==1||c1==0){
			cout<<"YES"<<endl;
		}
		else if(c1==3){
			if(c2!=1){
				cout<<"YES"<<endl;
			}else 
			cout<<"NO"<<endl;
		}
		else if(c1==2){
			cout<<"NO"<<endl;
		}
		
		
		
	}
	return 0;
}


