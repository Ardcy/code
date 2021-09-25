#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		if(k){
				cout<<2*i<<" "<<2*i-1<<" ";
			k--;	
		}else

		cout<<2*i-1<<" "<<2*i<<" ";
	}
	return 0;
}
