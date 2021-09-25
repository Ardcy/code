#include<bits/stdc++.h>
using namespace std;
#define int long long 
void get(int n){
	if(n==1){
		cout << "1/1" << endl;
		return;
	}
	
	int a=0,b=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(__gcd(i,j)==1){
				a++;
			}else{
				b++;
			}
		}
	}
	b = a+b;
	a *= (n/2);
	int c = __gcd(a,b);
	a/=c;
	b/=c;
	cout << a <<"/" << b <<endl;
}
signed main(){
	int n;
	
	cin >> n;
	get(n);

}