#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
signed main(){
	int n;
	cin>>n;
	int a=0,b=1,c=1,d=1;
	for(int i=2;i<=n;i++){
		int a1=a,b1=b,c1=c,d1=d;
		a=(b1+c1+d1);a%=mod;
		b=(a1+c1+d1);b%=mod;
		c=(a1+b1+d1);c%=mod;
		d=(a1+b1+c1);d%=mod;
//		cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	}
	cout<<a<<endl;
	return 0;
}
