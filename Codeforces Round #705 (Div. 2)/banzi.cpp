#include<bits/stdc++.h>
using namespace std;
#define int __int128
const int N = 1e5+5;
const int mod = 1e9+7;
int pri[N],vis[N],cnt,phi[N],mu[N];
int d[N],num[N];
int g[N],f[N];
void prime(){
	cnt = 0;
	mu[1] = 1;
	d[1] = 1;
	g[1] = f[1] = 1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			pri[cnt++] = i;
			phi[i] = i-1;
			mu[i] = -1;
			d[i] = 2;
			num[i] = 1;
			g[i] = i+1;
			f[i] = i+1;
		}
		for(int j=0;j<cnt&&i*pri[j]<N;j++){
			vis[i*pri[j]] = 1;
			if(i%pri[j]==0){
				mu[i*pri[j]] = 0; 	
				phi[i*pri[j]] = phi[i] * (pri[j]);
				num[i*pri[j]] = num[i]+1;
				d[i*pri[j]] = d[i] / num[i*pri[j]] * ( num[i*pri[j]] + 1);
				g[i * pri[j]] = g[i] * pri[j] + 1;
       		    f[i * pri[j]] = f[i] / g[i] * g[i * pri[j]];
				break;
			}else{
				num[i*pri[j]] = 1;
				d[i*pri[j]] = d[i]*2;
				phi[i*pri[j]] = phi[i] * (pri[j]-1);
				mu[i*pri[j]] = -mu[i];
				f[i * pri[j]] = f[i] * f[pri[j]];
      		    g[i * pri[j]] = 1 + pri[j];
			}
		}
	}
	// for(int i = 1 ;i < N;i++){
	// 	f[i] = (f[i-1] + f[i]) % mod;
	// }
}


int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x = 1;
		y = 0;
		return a;
	}
	int r = exgcd(b,a%b,x,y);
	int temp = x;
	x = y;
	y = temp - a/b * y;
	return r;
}



int m[N];
int a[N];
int flag;
int china2(int num){//不互质的中国剩余定理
    int m1=m[0],a1=a[0],m2,a2,k1,k2,x0,gcd,c;
	int lcm=m[0];

    for(int i=1;i<num;i++){
        m2=m[i],a2=a[i];
        c=a2-a1;
        gcd=exgcd(m1,m2,k1,k2);//解得：n1*k1+n2*k2=gcd(n1,n2)
        lcm=lcm/__gcd(lcm,m[i])*m[i];//通过这个循环求解出所有mod的最大公约数
        
        if(c%gcd){
           flag=1;//!!!!!!china也可以求解出为0的值，所以为0不一定就是无解，所以你要通过flag来判断是否无解。
           return 0;//无解
        }
        x0=c/gcd*k1;//n1*x0+n2*(c/gcd*k2)=c  PS:k1/gcd*c错误！
        int t=m2/gcd;
        x0=(x0%t+t)%t;//求n1*x0+n2*y=c的x0的最小解
        a1+=m1*x0;
        m1=m2/gcd*m1;
     }
     return a1;
}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int t;
ll n, p;
ll w;


struct num{
	ll x,y;
};
num mul(num a, num b, ll p) {  //复数乘法
  num ans = {0, 0};
  ans.x = ((a.x * b.x % p + a.y * b.y % p * w % p) % p + p) % p;
  ans.y = ((a.x * b.y % p + a.y * b.x % p) % p + p) % p;
  return ans;
}

ll binpow_real(ll a, ll b, ll p) {  //实部快速幂
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans % p;
}

ll binpow_imag(num a, ll b, ll p) {  //虚部快速幂
  num ans = {1, 0};
  while (b) {
    if (b & 1) ans = mul(ans, a, p);
    a = mul(a, a, p);
    b >>= 1;
  }
  return ans.x % p;
}

ll cipolla(ll n, ll p) {
  n %= p;
  if (p == 2) return n;
  if (binpow_real(n, (p - 1) / 2, p) == p - 1) return -1;
  ll a;
  while (1) {  //生成随机数再检验找到满足非二次剩余的a
    a = rand() % p;
    w = ((a * a % p - n) % p + p) % p;
    if (binpow_real(w, (p - 1) / 2, p) == p - 1) break;
  }
  num x = {a, 1};
  return binpow_imag(x, (p + 1) / 2, p);
}
signed main(){
	//freopen("P4777_15.in","r",stdin);
	cout << cipolla(3,5) << endl;
	
}