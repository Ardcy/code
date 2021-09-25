#include<bits/stdc++.h>
using namespace std;
#define int long long
int a = 1,b=0;
void gcd(int n){
	if(n==0)return ;
	swap(a,b);
	a = a+b;
	if(a==1)a=2;
	n--;
	gcd(n);
}
signed main() {
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		a = 1, b = 0;
		gcd(n);	
		cout<<(a+b)<<endl;
	}
	return 0;
}
