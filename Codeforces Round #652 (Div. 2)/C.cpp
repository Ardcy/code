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
bool cmp(int a1,int a2){
	return a1>a2;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int ans = 0;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int num = 0;
		for(int i=1;i<=k;i++){
			cin>>b[i];
			if(b[i]==1)num++;
		}
		sort(b+1,b+n+1,cmp);
		for(int i=n-num+1;i<=n;i++)ans+=a[i]+a[i];
		n=n-num;
		k=k-num;
		cout<<"ans="<<ans<<endl;
		int l = 1,r = n;
		for(int i=1;i<=k;i++){
			ans+=a[l]+a[r];
			l+=b[i]-1;
			r-=1;
		}
		
		
		
		
		cout<<ans<<endl;
	}
	return 0;
}


