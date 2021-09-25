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
	return fa[a]=fa[a]==a?a:find(fa[a]);
}
int unio(int a,int b){
	if(find(a)==find(b));else fa[find(a)]=find(b);
}
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int _=1;_<=m;_++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){      
			unio(b,c);
		}	
		else{
			if(find(c)==find(b)){
				cout<<"Y"<<endl;
			}else cout<<"N"<<endl;
		}
	}
}


