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

struct node{
	string x,y;
	int z;
	int p;
}e[1000];
bool  cmp(node a,node b){
	if(a.z==b.z)return a.p<b.p;
	return a.z <b.z;
}
signed main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		string s;
		cin>>s;
		e[i].x=s;
		cin>>s;
		e[i].y=s;
		int u;
		cin>>u;
		e[i].z=u;
		e[i].p=i;
	}
	sort(e+1,e+t+1,cmp);
	int l,r;
	cin>>l>>r;
	int f = 0;
	for(int i=t;i>=1;i--){
		if(e[i].z>=l&&e[i].z<=r){
			f++;cout<<e[i].x<<" "<<e[i].y<<endl;
		}
	}
	if(!f)cout<<"None"<<endl;
	return 0;
}


