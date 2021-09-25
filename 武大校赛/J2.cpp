#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+10;
#define int long long
typedef long long LL;
LL h[maxn],inv[maxn];
LL mod=998244353;
//扩展欧几里得 
void ex_gcd(LL a, LL b, LL &x, LL &y, LL &d){
    if (!b) {d = a, x = 1, y = 0;}
    else{
        ex_gcd(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}
//求逆元，调用扩展欧几里得
LL inva(LL t, LL p){//如果不存在，返回-1
    LL d, x, y;
    ex_gcd(t, p, x, y, d);
    return d == 1 ? (x % p + p) % p : -1;
}
int fac[1005000];
void init(){
	fac[0]=1;
	for(int i=1;i<=2*maxn;i++){
		fac[i]=fac[i-1]*i%mod;
	}
}
int qp(int a,int b,int mod){
	a%=mod;
	int ans=1;while(b){
		if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;
	}
	return ans;
} 
int c(int n,int m){
	int u = qp((fac[m]*fac[n-m])%mod,mod-2,mod);
	
	return fac[n]*u%mod;
}
signed main(){
	init();
    //cout<<c(10,2)<<endl;
	cin.sync_with_stdio(false);//解除cin的同步性，使得cin速度加快
    int t;
    cin>>t;
    
    //inv数组是逆元
    inv[1]=1;  
    //求解1-n的逆元
    for(int i=2;i<maxn;i++){
        inv[i]=(mod-mod/i)*1ll*inv[mod%i]%mod;
    }

    //h数组是卡特兰数
    h[0]=1;h[1]=1;  
    for(int i=2;i<=maxn-5;i++){
        h[i]=(h[i-1]%mod*(4*i-2)%mod*inv[i+1])%mod;
    }
	
   	//for(int i=1;i<=10;i++)cout<<h[i]<<endl;
   	int sum = 0;
   	for(int i=0;i<=t;i++){
   		sum+=h[i]*c(t+i,t-i);
   		//cout<<c(t+i,t-i)<<endl;
   		sum%=mod;
	}
   	cout<<sum<<endl;
   	
   	
}

