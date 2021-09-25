#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<'='<<x<<endl
#define int long long
double cnt;
const double eps = 1e-6;
double r3(double i){
	return i*i*i;
}
double qpow(double a)
{
	double l=0,r=100,mid;
	while(r3(l)<a&&r3(r)>a){
		mid = (l+r)/2;
		if(r3(mid)<a)l=mid;
		else r = mid;
		if(r-l<eps)return r;
	}
} 
signed main() {

	int T;
	cin>>T;
	double a,b;
	double o = 0.333;
	while(T--){
		cin>>a>>b;
		cnt = 0.0;
		if(a*b<eps){
			a=abs(a);
			b=-abs(b);
			o=qpow(a);
			while(o-b+1<a-b){
				cnt+=1;
				a=o;
				o=qpow(a);
			}
			printf("%.9f\n",(a-b+cnt));	
		}
		else{
			a=abs(a);
			b=abs(b);
			if(a<b){
				printf("%.9f\n",(b-a));
				continue;
			}
			o=qpow(a);
			while(abs(o-b)+1<a-b){
				cnt+=1;
				a=o;
				o=qpow(a);
				
			}
			printf("%.9f\n",(abs(a-b)+cnt));
			
		}
		
	}
}
