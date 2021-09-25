#include<bits/stdc++.h>
using namespace std;
#define double long double
const double eps = 1e-11;

double n,p1,v2,p2,v1;
bool check(double mid){
	double pre = min(n-p1,p1) + n;
	if(pre < mid*v1){
		return true;
	}
	pre = min(n-p2,p2) + n;
	if(pre < mid*v2){
		return true;
	}
	if(p1 > v1*mid || (n-p2) > v2*mid){
		return false;
	}
	
	if(p2 < mid * v2 && n-p1 < mid * v1){
		return true;
	}
	double l1,l2;
	l1 = max(v1*mid - p1, (v1 * mid - p1 )/2 + p1);
	

	l2 = min(p2-(v2*mid-(n - p2))/2, p2 - mid*v2 + 2*(n-p2));
	
	if(l1 > l2 || l1 > p2 || l2 < p1 || l2 < 0 || l1 > n){
		return true;
	}
	return false;
}
signed main(){
	int t;
	cin >> t;
	while(t--){	
		cin >> n >> p1 >> v1 >> p2 >> v2;
		if(p1 > p2){
			swap(p1,p2);
			swap(v1,v2);
		}
		double l = 0.0;
		double r = (2*n)/v1;
		double mid;
		for(int uu = 1;uu<=300;uu++){
			//cout << l << " " << r << endl;
			mid = (l+r)/2;
			if(!check(mid)){
				l = mid;
			}else{
				r = mid;
			}
		}
		printf("%.10Lf\n",l);
	}
}