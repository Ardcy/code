#include<bits/stdc++.h>
using namespace std;




double get_ans(double w,double g,double h,double r,double p){
	return sqrt((g-r)*(g-r)+p*p) + sqrt((h-r)*(h-r)+(w-p)*(w-p));
}
double sanfen(double w,double g,double h,double r1){
	double l=0;
	double r = w*1.0;
	double ans  = 1e15;
	while(fabs(r-l)>1e-8){
		double ml = (r+2*l)/3;
		double mr = (2*r+l)/3;
		if(get_ans(w,g,h,r1,ml) < get_ans(w,g,h,r1,mr)){
			r = mr;
			ans = min(ans,get_ans(w,g,h,r1,ml));
		}else{
			ans = min(ans,get_ans(w,g,h,r1,mr));
			l = ml;
		}
	}
	//cout << l << endl;
	return ans;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		double w,g,h,r;
		cin >> w >> g >> h >>r;

		double ans1 = sqrt(w*w+fabs(h-g)*fabs(h-g));

		double ans2 = sanfen(w,g,h,r);
		printf("%.10f %.10f\n",ans1,ans2);
		
	}
}