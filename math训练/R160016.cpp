#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n,a,b,p,q;
	cin>>n>>a>>b>>p>>q;
	int t1 = n/a;
	int t2 = n/b;
	int t3 = n/(a*b/__gcd(a,b));
	if(p>q){
		cout<<t1*p+(t2-t3)*q<<endl;
	}
	else{
		cout<<t2*q+(t1-t3)*p<<endl;
	}
	return 0;
}
