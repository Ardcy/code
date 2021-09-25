#include<bits/stdc++.h>
using namespace std;

signed main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		int k = __gcd(a,b);
		a/=k;
		b/=k;
		int flag = 0;
		
		int p  = (a + sqrt(a*a-4*b))/2;
		if(p * p - p*a + b==0){
			flag = 1;
			cout <<( a-p)*k << " " << p*k << endl;
		}
		if(flag == 0){
			cout << "No Solution" << endl;
		}
	}
}