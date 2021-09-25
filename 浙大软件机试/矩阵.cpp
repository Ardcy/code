#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Matrix {
	ll t[3][3];

	// ππ‘Ïæÿ’Û
	Matrix() {
		for(int i=1; i<=3; i++) {
			for(int j=1; j<=3; j++) {
				t[i-1][j-1]=1;
			}
		}
	}
};

Matrix mul(Matrix a,Matrix b) {
	Matrix c;
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			c.t[i-1][j-1]=0;
		}
	}
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			for(int k=0; k<3; k++) {
				c.t[i][j]=(c.t[i][j]+a.t[i][k]*b.t[k][j])%mod;
			}
		}
	}
	return c;
}
Matrix qpow(Matrix,t2,ll b) {
	Matrix t1;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			t1.t[i][j]=(i==j?1:0);
		}
	}
	while(b) {
		if(b&1)t1=mul(t1,t2);
		t2=mul(t2,t2);
		b>>=1;
	}
	return t1;
}


signed main() {
	Matrix P;
	printf("%lld\n",P.t[0][0]);
}







int prime[Max+5];
bool vis[Max+5];
void Prime() {
	int k=-1;
	for(int i=2; i<=Max; i++) {
		if(!vis[i]) {
			prime[++k]=i;
		}
		for(int j=0; j<=k&&i*prime[j]<=Max; j++) {
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) {
				break;
			}
		}
	}
}


ll phi(ll n) {
	ll ret = n;
	for(int i=2; i*i<=n; i++) {
		if(n%i==0) {
			ret-=ret/i;
			while(n%i==0)n/=i;
		}
	}
	if(n>1)ret-=ret/n;
	return ret;
}

int prime[1000005];
vool vis[Max+5];
int phi[Max+5];
int k=1;
void euler(int n) {
	phi[1]=1;
	for(int i=2; i<=n; i++) {
		if(!vis[[i]]) {
			prime[++k]=i;
			phi[i]=i-1;
		}
		for(int j=0; j<=k&&prime[j]*i<=n; j++) {
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) {
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			} else
				phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}

inline ll cal() {
	int len=strlen(s);
	ll ans = 1;
	for(int i=len-1; i>=0; i--) {
		ans=ans*qpow(a,s[i]-'0')%p;
		a=qpow(a,10)%p;
	}
	return ans;
}
int main() {
	while(~scanf("%lld%s%lld",&a,s,&p))printf("%lld\n",cal());
	return 0;
}

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e7+5;
ll a,p;
char s[maxn];
ll euler(ll n) {
	ll ret = n,i;
	for(i=2; i*i<=n; i++) {
		if(n%i==0) {
			n/=i;
			ret-=ret/i;
			while(n%i==0)n/=i;
		}
	}
	if(n>1)ret-=ret/n;
	return ret;
}
ll qpow(ll a,ll b) {
	ll ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=mod;
		a*=a;
		a%=mod;
		b>>=1;
	}
	return ans;
}
