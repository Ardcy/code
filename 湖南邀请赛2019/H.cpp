#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
namespace ztd{
    using namespace std;
    typedef long long ll;
    template<typename T> inline T read(T& t) {//fast read
        t=0;short f=1;char ch=getchar();double d = 0.1;
        while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar();}
        while (ch>='0'&&ch<='9') t=t*10+ch-'0',ch=getchar();
        if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
        t*=f;
        return t;
    }
}
using namespace ztd;
const int maxn = 1e6+7;
const int mod = 1e9+7;
const ll INV6 = 166666668;//Ԥ����6����Ԫ
ll n, sqrn;
inline ll f(ll x){//�����f�������䶨����ֻ��prime^k
	x %= mod;
	return x*(x-1)%mod;
}
ll prime[maxn], sump1[maxn], sump2[maxn], pcnt;
//sump1��sump2�ֱ���������ǰ׺���Լ�����ǰ׺��(2^2+3^2+5^2����)
bool vis[maxn];
inline void preprocess_prime(int uplimit){//����ɸɸ����
    for(int i = 2; i <= uplimit; ++i){
        if(!vis[i]){
        	prime[++pcnt] = i;
        	sump1[pcnt] = (sump1[pcnt-1]+i) % mod;
        	sump2[pcnt] = (sump2[pcnt-1]+1ll*i*i%mod) % mod;
        } 
        for(int j = 1; j <= pcnt && i*prime[j] <= uplimit; ++j){
            vis[i*prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

ll g1[maxn], g2[maxn], match1[maxn], match2[maxn], w[maxn], tot;
//g1,g2��������˵�� match1��match2��w����������˵����ɢ���ˡ�
// w[j]��ʾ ��i�����۷ֿ�ĳ��ȡ� 
inline void preprocess_g(){//Ԥ����g����ɢ��
	ll tmp;
	for(ll l = 1, r = 0; l <= n; l = r+1){
		r = n/(n/l); ++tot;
		w[tot] = n/l;
		
		//����һ��map 
		if(w[tot] < sqrn) match1[n/l] = tot;
		else match2[n/(n/l)] = tot;
		
		tmp = w[tot] % mod;
		g1[tot] = tmp * (tmp+1) / 2 % mod-1;
		g2[tot] = tmp * (tmp+1) % mod * (tmp*2+1) % mod * INV6 % mod - 1;
	}
}
inline void process_g(){//g�ĵ���
	for(int i = 1; i <= pcnt && prime[i]*prime[i] <= n; ++i){
		// ö�� prime[i]
		 
		for(int j = 1; j <= tot && 1ll*prime[i]*prime[i] <= w[j]; ++j){
			ll pmt = w[j]/prime[i];
			// ����Ҫ���ÿ��w[j]��ֵ�� 
			ll tmp = (pmt >= sqrn) ? (match2[n/pmt]) : (match1[pmt]);
			
			
			g1[j] = (g1[j] - prime[i] * (g1[tmp]-sump1[i-1]+mod) % mod  % mod + mod) % mod;
			g2[j] = (g2[j] - prime[i]*prime[i]%mod * (g2[tmp]-sump2[i-1]+mod) % mod + mod) % mod;
		}
	}
}
ll S(ll N, ll y){//�����𰸵�
	if(prime[y] > N) return 0;
	ll k = (N >= sqrn) ? (match2[n/N]) : (match1[N]);
	ll prans = (g2[k]-g1[k]+mod - (sump2[y-1]-sump1[y-1])+mod) % mod;//ָ��������Ľ��
	ll cpans = 0;//��������Ľ��
	for(int i = y; i <= pcnt && 1ll * prime[i]*prime[i] <= N; ++i){
		for(ll pk = prime[i]; prime[i]*pk <= N; pk *= prime[i]){
			cpans = (cpans + (f(pk) * S(N/pk, i+1) % mod + f(prime[i]*pk)) % mod) %mod;
		}
	}
	return (prans+cpans) % mod;
}
signed main(){
    read(n);  sqrn = sqrt(n);
    preprocess_prime(maxn-5);
    preprocess_g();
    process_g();
    cout << (S(n,1) + 1) % mod << '\n';//����ⶨ����f(1)=1
    return 0;
}
