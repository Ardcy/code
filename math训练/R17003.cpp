#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int a,b,x,y,sum;
signed main(){
	cin>>a>>b;
	x=b*(b-1)/2;
	x%=mod;
	y=(a*(a+1)/2)%mod;
	cout<<(x*((y*b)%mod+a))%mod<<endl;
	return 0;
}
