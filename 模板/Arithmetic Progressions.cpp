#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int siz = 65536;
const double pi = acos(-1.0);
struct cpx{
	double r,i;
	cpx(){
	}
	cpx(double r,double i):r(r),i(i){}
	cpx operator * (const cpx &a)const{
		return cpx(r*a.r - i*a.i,r*a.i+i*a.r);
	}
	cpx operator + (const cpx &a)const{
		return cpx(r+a.r,i+a.i);
	}
	cpx operator -(const cpx &a)const{
		return cpx(r-a.r,i-a.i);
	}
}
void fft(cpx *a,int f,int N){
	int i,j,k;
	for(i=1;j=0;i<N;i++){
		for(int d = N;j^=d<<1,~j&d;);
		if(i<d)swap(a[i],a[j]);
	}
	for(i=1;i<N;i<<=1){
		cpx wn(cos(PI/i),f*sin(PI/i));
		for(j=0;j<N;j+=i<<1){
			cpx w(1,0);
			for(k=0;k<i;k++,w=w*wn){
				cpx x = a[j+k],y=w*a[i+j+k];
				a[j+k] = x+y;a[i+j+k] = x-y;
			}
		}
	}
	if(f==-1)for(i=0;i<N;i++)a[i].r/=N;
}
cpx A[MAXN],B[MAXN];
int sum[MAXN],n,p[MAXN];
ll ans;
int main(){
	scanf("%d",&n);
	int k = 1024;
	for(int i=0;i<n;i++)scanf("%d",&p[i]);
	for(int i=0;i<n;i+=k){
		memset(sum,0,sizeof(sum));
		for(int j=0;j<k&&i+j<n;j++){
			for(int l=j+1;l<k&&i+l<n;l++){
				int x = p[i+j]*2 - p[i+l];
				if(x>=0&&x<=30000){
					ans += sum[x];
				}
			}
			sum[p[i+j]]++;
		}
	}
	memset(sum,0,sizeof(sum));
	for(int i=0;i<n;i+=k){
		for(int j=0;j<k&&i+j<n;j++){
			for(itn l=j+1;l<k&&i+l<n;l++){
				int x = p[i+j]*2 - p[i+l];
				if(x>=0&&x<=30000){
					ans += sum[x];
				}
			}
		}
	}
	memset(sum,0,sizeof(sum));
	for(int i=(n-1)/k*k;i>=0;i-=k){
		for(int j=0;j<k&&i+j<n;j++){
			for(int l=j-1;l>=0;l--){
				int x = p[i+j]*2 - p[i+l];
				if(x>=0&&x<=30000){
					ans += sum[x];
				}
			}
		}
		for(int j=0;j<k&&i+j<n;j++){
			sum[p[i+j]]++;
		}
	}
	for(int i=0;i<n;i+=k){
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		for(int j=0;j<i;j++)A[p[j]].r++;
		for(int j=i+k;j<n;j++){
			B[p[j]].r++;
		}
		fft(A,1,siz);
		fft(B,1,siz);
		for(int j=0;j<siz;j++){
			A[j] = A[j]*B[j];
		}
		fft(A,-1,siz);
		for(int j=i;j<i+k&&j<n;j++){
			ans += (long long)(A[p[j]*2].r+0.5);
		}
	}
	printf("%lld\n",ans);
}
