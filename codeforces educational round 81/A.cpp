#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#define ll long long
using namespace std;
ll getphi(ll x){
	ll ret = x;
	for(ll i=2; i*i<=x; i++)
		if(x%i==0){
			ret -= ret / i;
			while(x%i==0) x /= i;
		}
	if(x > 1) ret -= ret / x;
	return ret;
}
int main()
{
	int T;
	cin>>T;
	while(T--){
		long long int m,n;
		cin>>n>>m;
		long long c=__gcd(m,n);
		printf("%lld\n",getphi(m/c));		
	}
    
    return 0;
}
