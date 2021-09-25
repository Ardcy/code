#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 17
const int MOD = 998244353;
template<typename T>
inline void read(T&x){
	T f = 1,c=0;char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f = -1;ch = getchar();}
	while(ch>='0'&&ch<='9'){c = c*10+ch-'0';ch=getchar();}
	x = f*c;
}
int n;
ll inv_2 = (MOD+1)/2;
ll a[(1<<N)+5],b[(1<<N)+5],c[(1<<N)+5];
void Mod(ll &x){if(x>=MOD)x-=MOD;}
void fwt_or(ll *a,int len,int k){
	for(int i=1;i<len;i<<=1){
		for(int j=0;j<len;j+=(i<<1)){
			for(int o=0;o<i;o++){
				if(k==1)Mod(a[j+o+i]+=a[j+o]);
				else Mod(a[j+o+i] += -a[j+o]+MOD);
			}
		}
	}
}
void fwt_and(ll *a,int len,int k){
	for(int i=1;i<len;i<<=1){
		for(int j=0;j<len;j+=(i<<1)){
			for(int o=0;o<i;o++){
				if(k==1)Mod(a[j+o]+=a[j+o+i]);
				else Mod(a[j+o]+=a[j+o+i]+MOD);
			}
		}
	}
}
void fwt_xor(ll *a,int len,int k){
	for(int i=1;i<len;i<<=1){
		for(int j=0;j<len;j+=(i<<=1)){
			for(int o=0;o<i;o++){
				int w1 = a[j+o],w2=a[j+o+i];
				a[j+o] = (w1+w2)%MOD;
				a[j+o+i] = (w1-w2+MOD)%MOD;
				if(k==-1)a[j+o]=a[j+o]*inv_2%MOD,a[j+o+i]=a[j+o+i]*inv_2%MOD;
			}
		}
	}
}
void mul(){
	for(int i=0;i<(1<<n);i++){
		printf("%lld ",c[i]);
	}
	puts("");
}
int main(){
	read(n);int len = (1<<n);
	for(int i=0;i<len;i++){
		read(a[i]);
	}
	for(int i=0;i<len;i++){
		read(b[i]);
	}
	fwt_or(a,len,1);fwt_or(b,len,1);
	mul();
	fwt_or(a,len,1);fwt_or(b,len,1);
	mul();
	fwt_or(c,len,-1);
	fwt_or(a,len,-1),fwt_or(b,len,-1);
}