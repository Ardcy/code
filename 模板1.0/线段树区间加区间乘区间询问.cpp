#include<cstdio>
#include<iostream>
#define LL long long int 
#define ls o<<1
#define rs o<<1|1
#define M ((L+R)>>1)
using namespace std;
const int maxn = 100010;
LL n, m, p;
LL A[maxn], sumv[maxn*4], addv[maxn*4], mulv[maxn*4];
LL add(LL a,LL b) {//方便取模 
	return (a+b)%p;
}
LL mul(LL a,LL b) {
	return (a*b)%p;
}
inline void build(LL o,LL L,LL R) {
	mulv[o] = 1;
	if(L == R) sumv[o] = A[L] % p;
	else {
		build(ls,L,M);
		build(rs,M+1,R);
		sumv[o] = add(sumv[ls],sumv[rs]);
	}
}
inline void pushdown(LL o,LL L,LL R) {//划重点 
	sumv[ls] = mul(sumv[ls],mulv[o]);
	sumv[rs] = mul(sumv[rs],mulv[o]);
	sumv[ls] = add(sumv[ls],addv[o]*(M-L+1)); 
	sumv[rs] = add(sumv[rs],addv[o]*(R-M));
	mulv[ls] = mul(mulv[ls],mulv[o]);
	mulv[rs] = mul(mulv[rs],mulv[o]);
	addv[ls] = mul(addv[ls],mulv[o]);
	addv[rs] = mul(addv[rs],mulv[o]);
	addv[ls] = add(addv[ls],addv[o]);
	addv[rs] = add(addv[rs],addv[o]);
	addv[o] = 0;
	mulv[o] = 1;	 
}
LL ql,qr,qa,qm;
inline void updatea(LL o,LL L,LL R) {
	if(ql <= L &&  R <= qr) {
		addv[o] = add(addv[o],qa);
		sumv[o] = add(sumv[o],qa*(R-L+1));
		return;
	}
	pushdown(o,L,R);
	if(ql <= M) updatea(ls,L,M);
	if(qr > M) updatea(rs,M+1,R);
  sumv[o] = add(sumv[ls], sumv[rs]);
}
inline void updatem(LL o,LL L,LL R) {
  if(ql <= L && R <= qr) {
  	mulv[o] = mul(mulv[o],qm);
  	addv[o] = mul(addv[o],qm);//加法标记*c 
  	sumv[o] = mul(sumv[o],qm);
  	return;
	}	
	pushdown(o,L,R);
	if(ql <= M) updatem(ls,L,M);
	if(qr > M) updatem(rs,M+1,R);
	sumv[o] = add(sumv[ls], sumv[rs]);
}

inline LL query(LL o,LL L,LL R) {
	if(ql <= L && R <= qr) return sumv[o];
	pushdown(o,L,R);
	LL ret = 0;
	if(ql <= M) ret = add(ret, query(ls,L,M));
	if(qr > M) ret = add(ret, query(rs,M+1,R));
	return ret%p;
}

int main() {
	cin >> n >> m >> p;
	for(int i = 1;i <= n;i++) scanf("%lld",&A[i]);
	build(1,1,n);
	for(int i = 1,x;i <= m;i++) {
		scanf("%d",&x);
		if(x == 1) {
			scanf("%lld%lld%lld",&ql,&qr,&qm);
			updatem(1,1,n);
		} else if(x == 2) {
			scanf("%lld%lld%lld",&ql,&qr,&qa);
			updatea(1,1,n);
		} else {
			scanf("%lld%lld",&ql,&qr);
			printf("%lld\n", query(1,1,n));
		}
	}
	return 0;
} 


