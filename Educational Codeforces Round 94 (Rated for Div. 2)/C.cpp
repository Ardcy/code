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
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		
		int n;
		cin>>n;
		
		string ans1;
		set<int>P;
		int l = s.length();
		for(int i=0;i<l;i++){
			if(s[i]=='0'){
				//cout<<i<<endl;
				if(i+n<l){
					P.insert(i+n);
				}
				if(i-n>=0){
					P.insert(i-n);
				}
			}
		}
		//for(auto p:P)cout<<p<<endl;
	//	cout<<P.count(3)<<endl;
		for(int i=0;i<l;i++){
			if(P.count(i)){
				ans1+='0';
			}else
			ans1+='1';
		}
	//	cout<<ans1<<endl;
		string h;
		for(int i=0;i<l;i++){
			int f = 0;
			if(i-n>=0){
				if(ans1[i-n]=='1')f=1;
			}
			if(i+n<l){
				if(ans1[i+n]=='1')f=1;
			}
			if(f)h+='1';else h+='0';
		}
		int f1 = 1;
		for(int i=0;i<l;i++){
			if(h[i]!=s[i])f1 = 0;
		}		
		if(f1)cout<<ans1<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}


