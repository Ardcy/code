#include<bits/stdc++.h>
#define ll long long
#define re register
#define gc get_char
#define cs const

namespace IO{
	inline char get_char(){
		static cs int Rlen=1<<20|1;
		static char buf[Rlen],*p1,*p2;
		return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,Rlen,stdin),p1==p2)?EOF:*p1++; 
	}
	
	inline ll getint(){
		re char c;
		while(!isdigit(c=gc()));re ll num=c^48;
		while(isdigit(c=gc()))num=(num+(num<<2)<<1)+(c^48);
		return num;
	}
}
using namespace IO;

using std::cout;
using std::cerr;

cs int mod=1e9+9,sq5=616991993,inv2=(mod+1)/2;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int dec(int a,int b){return a<b?a-b+mod:a-b;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int quickpow(int a,int b,int res=1){
	while(b){
		if(b&1)res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
template<class ...Args>
inline int mul(int a,Args ...args){return mul(a,mul(args...));}
template<class ...Args>
inline int add(int a,Args ...args){return add(a,add(args...));}

cs int P=1e5+5;
int fac[P],ifac[P],inv[P],x[P],y[P];
inline int C(int n,int m){return mul(fac[n],ifac[m],ifac[n-m]);}

signed main(){
	x[0]=y[0]=fac[0]=ifac[0]=fac[1]=ifac[1]=inv[0]=inv[1]=1;
	x[1]=(sq5+1)/2;
	y[1]=mul(mod+1-sq5,inv2);
	for(int re i=2;i<P;++i){
		fac[i]=mul(fac[i-1],i);
		inv[i]=mul(inv[mod%i],mod-mod/i);
		ifac[i]=mul(ifac[i-1],inv[i]);
		x[i]=mul(x[i-1],x[1]);
		y[i]=mul(y[i-1],y[1]); 
	}
	int q=getint();
	cout<<q;
	while(q--){
		ll n=getint(),k=getint(),ans=0;
		cout<<n<<"\n";
		for(int re i=0;i<=k;++i){
			int a=mul(x[i],y[k-i]),val;
			if(a==1)val=mul(n%mod,C(k,i));
			else val=mul(C(k,i),dec(quickpow(a,(n+1)%(mod-1)),a),quickpow(a-1,mod-2));
			if((k-i)&1)ans=dec(ans,val);
			else ans=add(ans,val); 
		}
		cout<<mul(ans,quickpow(quickpow(sq5,k),mod-2))<<"\n";
	}
	return 0;
}

