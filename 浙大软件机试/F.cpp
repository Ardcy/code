#include<bits/stdc++.h>
const int N = 2e5+4;
using namespace std;

signed main(){
	int a,b;
	int t;
	cin>>t;
	while(t--){
		
		cin>>a>>b;
		if(a==1&&b==1){
			cout<<1<<endl;
		}else
		cout<<(a-2+b-1)/b+1<<endl;
	}
	
	return 0;
} 
