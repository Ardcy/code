#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n;
	cin>>n;
	double a=0,b=0;
	for(int i=1;i<=n;i++){
		cin>>b;
		a+=b;
		
	}
	printf("%.20f\n",(a/(n*1.0)));
//	cout<<<<endl;
	return  0;
}
