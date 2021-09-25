// #include<bits/stdc++.h>
// using namespace std;
// const int N = 3e5+5, P = 998244353, gen = 3, igen = (P+1)/gen;
// int add(int x,int y){return x+y>=P?x+y-P:x+y;}
// int sub(int x,int y){return x-y<0?x-y+P:x-y;}
// int fpow(int a,int b){
// 	int ans=1;
// 	while(b){
// 		if(b)ans *= a,ans %=P;a*=a,a%=P;b>>=1;
// 	}return ans;
// }
// namespace Poly{
// 	int rev[N];
// 	void init(int n){
// 		for(int i=0;i<n;i++){
// 			rev[i] = rev[i>>1]>>1|((i&1)?n>>1:0);
// 		}
// 	}
// 	void ntt(int *f,int n,int flg){
// 		for(int i=0;i<n;i++){
// 			if(rev[i] < i)swap(f[i],f[rev[i]]);
// 		}
// 		for(int len=2,k=1;len<=n;len<<=1,k<<=1){
// 			int wn = fpow(flg ==1?gen:igen,(P-1)/len);
// 			for(int i=0;i<n;i+=len){
// 				for(int j=i,w=1;j<i+k;j++,w=1ll*w*wn%P){
// 					int tmp = 1ll*w*f[j+k]%P;
// 					f[j+k]=sub(f[j],tmp);
// 					f[j] = add(f[j],tmp);
// 				}
// 			}
// 		}
// 		if(flg == -1){
// 			int inv = fpow(n,P-2);
// 			for(int i=0;i<n;i++)f[i] = 1ll*f[i]*inv%P;
// 		}
// 	}
// 	#define glim(n) int limit=1;while(limit<=(n))limit<<=1;init(limit)
// 	void getinv(int *f,int n,int *G){
// 		if(n==1){
// 			G[0] = fpow(f[0],P-2);return;
// 		}
// 		getinv(f,(n+1)>>1,G);glim(2*n);
// 		static int F[N];
// 		for(int i=0;i<limit;i++){
// 			i>=n?F[i] = G[i] = 0:F[i] = f[i],G[i] = G[i];
// 		}
// 		ntt(F,limit,1),ntt(G,limit,1);
// 		for(int i=0;i<limit;i++){
// 			G[i] = 1ll*G[i]*sub(2,1ll*F[i]*G[i]%P)%P;
// 		}
// 		ntt(G,limit,-1);
// 		for(int i=n;i<limit;i++)G[i] = 0;
// 	}
// 	void dao(int *f,int n,int *G){
// 		static int F[N];
// 		for(int i=0;i<=n;i++)F[i] = f[i];
// 		for(int i=1;i<=n;i++){
// 			G[i-1] = 1ll*F[i]*i%P;G[n] = 0;
// 		}
// 	}
// 	void jifen(int *f,int n,int *G){
// 		static int F[N];
// 		for(int i=0;i<=n;i++)F[i] = f[i];
// 		for(int i=0;i<=n;i++){
// 			G[i+1] = 1ll*F[i]*fpow(i+1,P-2)%P;
// 		}G[0] = 0;
// 	}
// 	void getln(int *f,int n,int *G){
// 		static int F[N],iF[N];
// 		for(int i=0;i<n;i++)F[i] = f[i];
// 		getinv(F,n,iF),dao(F,n-1,F);glim(n*2);
// 		for(int i=0;i<limit;i++)F[i]=i>=n?0:F[i],iF[i]=i>=n?0:iF[i];
// 		ntt(F,limit,1),ntt(iF,limit,1);
// 		for(int i=0;i<limit;i++)G[i] = 1ll*F[i]*iF[i]%P;
// 		ntt(G,limit,-1),jifen(G,n-1,G);
// 		for(int i=n;i<limit;i++)G[i] = 0;
// 	}
// 	void getexp(int *f,int n,int *G){
// 		if(n==1){
// 			G[0] = 1;return;
// 		}
// 		getexp(f,(n+1)>>1,G);
// 		glim(n*2);
// 		static int F[N],lnG[N];
// 		for(int i=0;i<limit;i++){
// 			i>=n?F[i] = G[i] = 0:F[i] = f[i],G[i] = G[i];
// 		}
// 		getln(G,n,lnG),ntt(F,limit,1),ntt(G,limit,1),ntt(lnG,limit,1);
// 		for(int i=0;i<limit;i++){
// 			G[i] = 1ll*G[i]*add(sub(1,lnG[i]),F[i])%P;
// 		}
// 		ntt(G,limit,-1);
// 		for(int i=n;i<limit;i++)G[i] = 0;
// 	}
// }
// int F[N],ans[N],inv[N],cnt[N];
// int main(){
// 	int n,m;
// 	scanf("%d%d",&n,&m);
// 	inv[1] = 1;
// 	for(int i=2;i<=m;i++){
// 		inv[i] = 1ll*(P-P/i)*inv[P%i]%P;
// 	}
// 	for(int _=1;_<=n;_++){
// 		int v;
// 		scanf("%d",&v);
// 		if(v<=m)cnt[v] = add(cnt[v],1);
// 	}
// 	for(int v = 1;v<=m;v++){
// 		if(cnt[v]){
// 			for(int i=1;i*v<=m;i++){
// 				F[i*v] = add(F[i*v],1ll*cnt[v]*inv[i]%P);
// 			}
// 		}
// 	}
// 	Poly::getexp(F,m+1,ans);
// 	for(int i=1;i<=m;i++){
// 		printf("%d\n",ans[i]);
// 	}
// }
// 
// 
// 
// 
#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10,P=998244353,gen=3,igen=(P+1)/gen;
int add(int x,int y){return x+y>=P?x+y-P:x+y;}
int sub(int x,int y){return x-y<0?x-y+P:x-y;}
int fpow(int x,int y){
    int ret=1; for(x%=P;y;y>>=1,x=1ll*x*x%P)
        if(y&1) ret=1ll*x*ret%P;
    return ret;
}
namespace Poly{
    int rev[N];
    void init(int n){
        for(int i=0;i<n;i++)
            rev[i]=rev[i>>1]>>1|((i&1)?n>>1:0);
    }
    void ntt(int *f,int n,int flg){
        for(int i=0;i<n;i++)
            if(rev[i]<i) swap(f[i],f[rev[i]]);
        for(int len=2,k=1;len<=n;len<<=1,k<<=1){
            int wn=fpow(flg==1?gen:igen,(P-1)/len);
            for(int i=0;i<n;i+=len)
                for(int j=i,w=1;j<i+k;j++,w=1ll*w*wn%P){
                    int tmp=1ll*w*f[j+k]%P;
                    f[j+k]=sub(f[j],tmp),f[j]=add(f[j],tmp);
                }
        }
        if(flg==-1){
            int inv=fpow(n,P-2);
            for(int i=0;i<n;i++) f[i]=1ll*f[i]*inv%P;
        }
    }
    #define glim(n) int limit=1;while(limit<=(n))limit<<=1;init(limit)
    void getinv(int *f,int n,int *G){
        if(n==1){G[0]=fpow(f[0],P-2);return;}
        getinv(f,(n+1)>>1,G); glim(2*n);
        static int F[N];
        for(int i=0;i<limit;i++)
            i>=n?F[i]=G[i]=0:F[i]=f[i],G[i]=G[i];
        ntt(F,limit,1),ntt(G,limit,1);
        for(int i=0;i<limit;i++) G[i]=1ll*G[i]*sub(2,1ll*F[i]*G[i]%P)%P;
        ntt(G,limit,-1);
        for(int i=n;i<limit;i++) G[i]=0;
    }
    void dao(int *f,int n,int *G){
        static int F[N]; for(int i=0;i<=n;i++) F[i]=f[i];
        for(int i=1;i<=n;i++) G[i-1]=1ll*F[i]*i%P; G[n]=0;
    }
    void jifen(int *f,int n,int *G){
        static int F[N]; for(int i=0;i<=n;i++) F[i]=f[i];
        for(int i=0;i<=n;i++) G[i+1]=1ll*F[i]*fpow(i+1,P-2)%P; G[0]=0;
    }
    void getln(int *f,int n,int *G){
        static int F[N],iF[N]; for(int i=0;i<n;i++) F[i]=f[i];
        getinv(F,n,iF),dao(F,n-1,F); glim(n*2);
        for(int i=0;i<limit;i++) F[i]=i>=n?0:F[i],iF[i]=i>=n?0:iF[i];
        ntt(F,limit,1),ntt(iF,limit,1);
        for(int i=0;i<limit;i++) G[i]=1ll*F[i]*iF[i]%P;
        ntt(G,limit,-1),jifen(G,n-1,G);
        for(int i=n;i<limit;i++) G[i]=0;
    }
    void getexp(int *f,int n,int *G){
        if(n==1){G[0]=1;return;}
        getexp(f,(n+1)>>1,G); glim(n*2);
        static int F[N],lnG[N];
        for(int i=0;i<limit;i++) i>=n?F[i]=G[i]=0:F[i]=f[i],G[i]=G[i];
        getln(G,n,lnG),ntt(F,limit,1),ntt(G,limit,1),ntt(lnG,limit,1);
        for(int i=0;i<limit;i++) G[i]=1ll*G[i]*add(sub(1,lnG[i]),F[i])%P;
        ntt(G,limit,-1);
        for(int i=n;i<limit;i++) G[i]=0;
    }
}
int F[N],ans[N],inv[N],cnt[N];
int main(){
    int n,m; scanf("%d%d",&n,&m);
    inv[1]=1; for(int i=2;i<=m;i++)
        inv[i]=1ll*(P-P/i)*inv[P%i]%P;
    for(int _=1;_<=n;_++){
        int v;scanf("%d",&v);
        if(v<=m) cnt[v]=add(cnt[v],1);
    }
    for(int v=1;v<=m;v++) if(cnt[v])
        for(int i=1;i*v<=m;i++) F[i*v]=add(F[i*v],1ll*cnt[v]*inv[i]%P);
    Poly::getexp(F,m+1,ans);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}