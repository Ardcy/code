#include<bits/stdc++.h>
using namespace std;
signed main(){
	long long l,r;
	cin >> l >> r;
	long long x1 = l/__gcd(l,r);
	long long y1 = r/__gcd(l,r);
	if((x1&1)&&(y1&1))
	cout <<__gcd(l,r)<<endl;
	else{
		cout <<0 << endl;
	}
}