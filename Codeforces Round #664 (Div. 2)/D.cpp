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
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};
int inv[N],fac[N],rev[N];
void init(int n) {
	fac[0]=1;
	rev[n]=1;
	for(int i=1; i<=n; i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1; i>=0; i--)rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1; i<n; i++)inv[i]=(rev[i]*fac[i-1]%mod)%mod;
}
int a[N],b[N];
bool cmp(int x,int y) {
	return x>y;
}
int sum1[N],sum2[N];
signed main() {
	int n,d,m;
	cin>>n>>d>>m;
	int cnt1 = 1;
	int cnt2 = 0;
	for(int i=1,u; i<=n; i++) {
		cin>>u;

		if(u>m)b[cnt2++]=u;
		else a[cnt1++]=u;
	}
	cnt1--,cnt2--;
	sort(a+1,a+cnt1+1);
//	for(int i=1;i<=cnt1;i++){
//		cout<<a[i]<<" ";
//	}cout<<endl;
	sort(a+1,a+cnt1+1,cmp);
	sort(b,b+cnt2+1,cmp);

	for(int i=1; i<=cnt1; i++) {
		sum1[i]=sum1[i-1]+a[i];
	}

	for(int i=1; i<=cnt2; i++) {
		sum2[i]=sum2[i-1]+b[i];
	}
//	cout<<b[0]<<" ";
//	for(int i=1;i<=cnt2;i++){
//		cout<<b[i]<<" ";
//	}cout<<endl;

//	cout<<sum1[cnt1]<<endl;
	if(!cnt2) {
		int ans =0;
		for(int i=1; i<=n; i++)ans+=a[i];
		cout<<ans<<endl;
		return 0;
	}

	int ans = 0;

//	cout<<cnt2<<endl;

	int f1 = (cnt2+d-1)/(d-1);
//	cout<<f<<endl;

	for(int f=f1; f<=cnt2; f++) {
		// f*d¿Õ

		//cout<<cnt1 -  f*d+cnt2-f<<endl;
		if(cnt1 -  f*d+cnt2-f>=0 &&cnt1 -  f*d+cnt2-f<= cnt1)ans = max(sum2[f]+sum1[ cnt1 -  f*d+cnt2-f],ans);
		else {
			ans=max(ans,sum2[f]);
			break;
		}
	}

//	cout<<ans<<endl;
//	cout<<b[0]<<endl;
//	cout<<cnt1<<" "<<cnt2<<endl;
//
//	cout<<f<<endl;


	cout<<ans+b[0]<<endl;


	return 0;
}


