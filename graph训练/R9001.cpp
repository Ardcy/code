#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin>>n;
	if(n%2)cout<<3<<endl;
	else{
		if(n<998)cout<<n+2<<endl;
		else cout<<n-2<<endl;
	}
	return 0;
}
