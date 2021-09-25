#include<bits/stdc++.h>
using namespace std;

const int N = 300100,P = 998244353;
int r[N];
inline int qpow(int x,int y){
	int res(1);
	while(y){
		if(y&1)res = 1ll*res*x%P;
		x = 1ll*x*x%P;
		y >>= 1;
	}return res;
}

void ntt(int *x,int len,int opt){
	for(int i = 0;i<len;i++){
		if(r[i] < i)swap(x[i],x[r[i]]);
	}
	for(int m = 2;m<=len;m<<=1){
		int k = m>>1;
		int gn = qpow(3,(P-1)/m);
		for(int i = 0;i<len;i+=m){
			int g = 1;
			for(int j = 0;j<k;j++,g = 1ll*g*gn%P){
				int tmp = 1ll * x[i+j+k]*g%P;
				x[i+j+k] = (x[i+j]-tmp+P)%P;
				x[i+j] = (x[i+j]+tmp)%P;
			}
		}
	}
	if(opt == -1){
		reverse(x+1,x+len);
		int inv = qpow(len,P-2);
		for(int i = 0;i<len;++i)x[i] = 1ll*x[i]*inv%P;
	}
}
int A[N],B[N],C[N];
char a[N],b[N];
signed main(){
	while(~scanf("%s%s",&a,&b)){
		int len(1),n;
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		n = strlen(a);
		for(int i=0;i<n;i++)A[i] = a[n-i-1] - '0';
		while(len < (n<<1))len<<=1;
		// scanf("%s",&b);
		n = strlen(b);
		for(int i=0;i<n;i++)B[i] = b[n-i-1] - '0';
		while(len < (n<<1))len<<=1;
		for(int i = 0;i<len;i++)r[i] = (i&1)*(len>>1)+(r[i>>1]>>1);
		ntt(A,len,1);
		ntt(B,len,1);
		for(int i=0;i<len;i++){
			C[i] = 1ll*A[i]*B[i]%P;
		}
		ntt(C,len,-1);
		int len = 0;
		for(int i=0;i<len;i++){
			if(C[i] >= 10)len = i+1,C[i+1] += C[i]/10,C[i]%=10;
			if(C[i])len = max(len,i);
		}
		while(C[len]>=10)C[len + 1] += C[len]/10,C[len]%=10,len++;
		for(int i=len;~i;--i){
			putchar(C[i]+'0');
		}
		puts("");
	}

}