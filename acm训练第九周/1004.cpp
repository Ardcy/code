#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int a,b;
	int sum = 0;
	int t;
	cin>>t;
	while(t--){
		cin>>a;
		sum = 0;
		for(int i=1;i<=a;i++){
			cin>>b;
			sum+=b;
		}
		cout<<sum<<endl;
	}
	
}
