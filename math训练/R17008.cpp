#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	double m,r;
	cin>>m>>r;
	long double p = sqrt(2);
	double ans1 = 2*(m/3-1-2/m/m+11/m/3)*r;
	long double ans2 = 2*(1-2/m+1/m/m)*p*r;
	//cout<<<<endl;
	printf("%.10Lf\n",(ans1+ans2));
	return 0;
}
