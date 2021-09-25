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
int fa[N];
int find(int a){
	if(a!=fa[a]){
		fa[a]=find(fa[a]);
		return fa[a];
	}else{
		return a;
	}
}
void un(int a,int b){
	if(find(a)!=find(b)){
		fa[find(a)]=find(b);
	}
}
int y[N]={0};
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld: ",&k);
		
		int p;
		for(int j=1;j<=k;j++){
			cin>>p;
			if(y[p]==0)y[p]=i;
			else	
			un(y[p],i);
			
		}
		
		
	}
	map<int,int>P;
	for(int i=1;i<=n;i++){
		P[find(i)]++;
	}
	vector<int>v;
	for(auto p:P){
		v.pb(p.se);
	}
	sort(v.begin(),v.end());
	int l = v.size();
	cout<<l<<endl;
	for(int i=l-1;i>=0;i--){
		cout<<v[i];if(i!=0)cout<<" ";
	}
	return 0;
}


