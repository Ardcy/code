#include<bits/stdc++.h>
using namespace std;
#define int long long
int t=1;
signed main() {
	while(t--){
		int a,f=0;	
		cin>>a;
		for(int i=2;i<=1e18;i*=2){
			if(i==a)f=1;
		}
		if(f==1)cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;	
	}
	
}
