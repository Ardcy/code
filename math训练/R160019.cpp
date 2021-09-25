#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,k;
	cin>>n;
	cout<<2<<endl;
	for(k=2;k<=n;k++){
		cout<<(k*(k+1)*(k+1)-(k-1))<<endl;
	}
	
}
