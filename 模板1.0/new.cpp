#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
const int mod=1000000007;


mt19937 mrand(random_device {}());
int rnd(int x) {return mrand() % x;}
int qp(int a,int b) {int res=1;a%=mod;while(b) {if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}


const int N=1010000;
int C,fac[10010],n,mut,a[1001000];
int T,cnt,i,l,prime[N],p[N],psize = N,_cnt;
int _e[100],_pr[100];
vector<int> d;
inline int mul(int a,int b,int p) {return a*b%p;}

void prime_table() {
	for (int i=1; i<=psize; i++) p[i]=i;
	for (int i=2,tot=0; i<=psize; i++) {
		if (p[i]==i) prime[++tot]=i;
		for (int j=1; j<=tot && (t1=prime[j]*i)<=psize; j++) {
			p[t1]=prime[j];
			if (i%prime[j]==0) break;
		}
	}
}



void _factor(ll n) {
	for (int i=0; i<cnt; i++) {
		if (n%fac[i]==0) n/=fac[i],fac[cnt++]=fac[i];
	}
	if (n<=psize) {
		for (; n!=1; n/=p[n]) fac[cnt++]=p[n];
		return;
	}
	if (miller(n)) fac[cnt++]=n;
	else {
		ll x=rho(n);
		_factor(x);
		_factor(n/x);
	}
}
void dfs(ll x,int dep) {
	if (dep==_cnt) d.pb(x);
	else {
		dfs(x,dep+1);
		for (int i=1; i<=_e[dep]; i++) dfs(x*=_pr[dep],dep+1);
	}
}
void norm() {
	sort(fac,fac+cnt);
	_cnt=0;
	rep(i,0,cnt) if (i==0||fac[i]!=fac[i-1]) _pr[_cnt]=fac[i],_e[_cnt++]=1;
	else _e[_cnt-1]++;
}
vector<ll> getd() {
	d.clear();
	dfs(1,0);
	return d;
}
vector<ll> factor(ll n) {
	cnt=0;
	_factor(n);
	norm();
	return getd();
}
vector<PLL> factorG(ll n) {
	cnt=0;
	_factor(n);
	norm();
	vector<PLL> d;
	rep(i,0,_cnt) d.pb(mp(_pr[i],_e[i]));
	return d;
}
bool is_primitive(ll a,ll p) {
	assert(miller(p));
	vector<PLL> D=factorG(p-1);
	rep(i,0,SZ(D)) if (powl(a,(p-1)/D[i].fi,p)==1) return 0;
	return 1;
}

const int N=1010000;
vector<PLL>P;
int aa[20];
int main() {
	Factor::init(100000);
	

}
