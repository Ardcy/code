#include<bits/stdc++.h>
#define int long long
using namespace std;
const signed N = 5e6, NP = 5e6, SZ = N;
int n,P,inv2 ,inv6,s[N];
signed phi[N],p[NP],cnt,pn;
bool bp[N];
map<int,int>s_map;
int ksm(int a,int m){
	int res = 1;
	while(m){
		if((m&1))res = res * a % P;
		a = a*a%P,m>>=1;
	}
	return res;
}
void prime_work(signed k){
	bp[0] = bp[1] = 1,phi[1] = 1;
	for(signed i = 2;i<=k;i++){
		if(!bp[i])p[++cnt] = i,phi[i] = i-1;
		for(signed j = 1;j<=cnt&&i*p[j] <=k;j++){
			bp[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]] = phi[i]*p[j];
				break;
			}else{
				phi[i*p[j]]=phi[i]*phi[p[j]];
			}
		}

	}
	for(signed i = 1;i<=k;i++){
			s[i] = (1ll*i*i%P*phi[i]%P+s[i-1]%P);
	}
}
int s3(int k){
	return k%=P,(k*(k+1)/2)%P *((k*(k+1)/2)%P)%P;
}
int s2(int k){
	return k%=P,k*(k-1)%P*(k*2+1)%P*inv6%P;
}
int calc(int k){
	if(k<=pn)return s[k];
	if(s_map[k])return s_map[k];
	int res = s3(k) ,pre = 1, cur;
	for(int i=2,j;i<=k;i=j+1){
		j = k/(k/i),cur = s2(j);
		res = (res - calc(k/i)*(cur - pre)%P)%P,pre = cur;
	}
	return s_map[k] = (res+P)%P;
}
int solve(){
	int res = 0,pre = 0,cur;
	for(int i=1,j;i<=n;i=j+1){
		j = n/(n/i),cur = calc(j);
		res = (res+(s3(n/i)*(cur-pre))%P)%P,pre = cur;

	}
	return (res+P)%P;
}
struct cmp{
	bool operator()(const int &a,const int &b)const{
		return a < b;
	}
};
signed main(){
	priority_queue<int,vector<int>,cmp> p;
	scanf("%lld%lld",&P,&n);
	inv2 = ksm(2,P-2);
	inv6 = ksm(6,P-2);
	pn = (int)pow(n,0.666667);
	prime_work(pn);
	printf("%lld",solve());

}