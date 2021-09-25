#include<bits/stdc++.h>
using namespace std;

int main(){
	int m,n;
	long long int  mod = 1e9+7;
	long long int ans = 0;
	cin>>n>>m; 
	
	ans = (n - 1)*(m-2)%mod*2*m%mod+(m - 1)*(n-2)%mod*2*n%mod +2*(m-1)*(m-2)%mod*(n-2)+2*(n-1)*(n-2)%mod*(m-2);
	ans = ans%mod;
	cout<<(int)ans<<endl;
}
