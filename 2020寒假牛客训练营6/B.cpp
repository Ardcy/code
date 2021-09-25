#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<'='<<x<<endl
double ans[105000];
double ansl[105000];
double ansr[105000];
pair<double,double>P[105000];
int N;
double eps = 1e-10;
int main() {
	cin>>N;
	double a,b;
	double l = -10000, r = 10000;
	double maxl=0,maxr=0;
	for(int i=1;i<=N;i++){
		cin>>a>>b; 
		P[i].first = a;
		P[i].second = b;
		ansl[i]=((P[i].first+10000)*(P[i].first+10000)+P[i].second*P[i].second);
		ansr[i]=((P[i].first-10000)*(P[i].first-10000)+P[i].second*P[i].second);
		maxl=max(maxl,ansl[i]);
		maxr=max(maxr,ansr[i]);
		l = min(l,a);
		r = max(r,a);
	}
	
	
	while(abs(r-l)>eps){
		//debug(l);
		//debug(r);
		//debug(maxl);
		//debug(maxr);
		if(maxl>maxr){
			l = (l+r)/2;
			maxl = 0;
			for(int i=1;i<=N;i++){
				ansl[i]=((P[i].first-l)*(P[i].first-l)+P[i].second*P[i].second);
				maxl = max(maxl,ansl[i]);
			}
		}
		else {
			r = (l+r)/2;
			maxr = 0;
			for(int i=1;i<=N;i++){
				ansr[i]=((P[i].first-r)*(P[i].first-r)+P[i].second*P[i].second);
				maxr = max(maxr,ansr[i]);
			}
		}	
	}
	printf("%.6f\n",sqrt(maxl));
	
}

