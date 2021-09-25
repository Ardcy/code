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
int b[N];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)a[i]=0,b[i]=0;
		int cnt1=1,cnt2=1;
		int ans = 1;
		for(int i=1,u;i<=n;i++){
			
			cin>>u;
			if(i<=5)ans*=u;
			if(u>=0){
				a[cnt1++]=u;
			}else{
				b[cnt2++]=-u;
			}
		}
		sort(a+1,a+cnt1);
		sort(b+1,b+cnt2);
		if(cnt1>=6)ans=max(ans,a[cnt1-1]*a[cnt1-2]*a[cnt1-3]*a[cnt1-4]*a[cnt1-5]);
		if(cnt2>=3&&cnt1>=4)ans=max(ans,a[cnt1-1]*a[cnt1-2]*a[cnt1-3]*b[cnt2-1]*b[cnt2-2]);
		int ansp = 0;
		if(cnt1>=2&&cnt2>=5){
			ans=max(ans,a[cnt1-1]*b[cnt2-4]*b[cnt2-3]*b[cnt2-1]*b[cnt2-2]);
			
		//	ansp = a[cnt1-1]*b[cnt2-4]*b[cnt2-3]*b[cnt2-1]*b[cnt2-2];
		}

		if(cnt2>=6)ans=max(ans,-b[1]*b[2]*b[3]*b[4]*b[5]);
		if(cnt2>=4&&cnt1>=3)ans=max(ans,-b[1]*b[2]*b[3]*a[1]*a[2]);
		if(cnt2>=2&&cnt1>=5)ans=max(ans,-b[1]*a[4]*a[3]*a[1]*a[2]);
		cout<<ans<<endl;
		
	}
	return 0;
}


