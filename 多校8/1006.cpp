#include<bits/stdc++.h>
using namespace std;
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
struct edge {
	int x,y;
	edge(int x1=0,int x2=0):x(x1),y(x2) {}
} e[N];
int u,v;
int f = 1;
int k;
void kuo(edge A) {
	u = max(0,A.x-k);
	v = min((int)1e9,A.y+k);
}
void union1(edge A,edge B) {
	if(max(A.x,B.x)>min(A.y,B.y)) {
		f = 0;
	} else {
		u = max(A.x,B.x);
		v = min(A.y,B.y);
	}
}
signed main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n>>k;
		f=1;
		for(int i=1; i<=n; i++)
			scanf("%d%d",&e[i].x,&e[i].y);
		for(int i=1; i<n; i++) {
			kuo(e[i]);
			edge p(u,v);
			union1(p,e[i+1]);
			if(f==0) {
				break;
			} else {
				e[i+1].x=u,e[i+1].y=v;
			}
		}
		if(f==0) {
			cout<<"NO"<<endl;
		} else {
			int l = 0;
			for(int i=n; i>=1; i--) {
				b[l++]=(e[i].x);
				e[i].y=e[i].x;
				kuo(e[i]);
				edge p(u,v);
				union1(p,e[i-1]);
				e[i-1].x=u,e[i-1].y=v;
			}
			cout<<"YES"<<endl;
			for(int i=l-1;i>=0;i--){
				printf("%d ",b[i]);
			}cout<<endl;
		}
	}
	return 0;
}


