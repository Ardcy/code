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
int a[30];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		for(int i=0;i<26;i++)a[i]=0;
		cin>>n;
		string s;
		for(int i=1;i<=n;i++){
			cin>>s;
			int l = s.length();
			for(int i=0;i<l;i++)a[s[i]-'a']++;
		}
		int f = 0;
		for(int i=0;i<=25;i++){
			if(a[i]%n!=0){
				f = 1;
			}
		}
		if(f){
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	return 0;
}


