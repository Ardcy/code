#include<bits/stdc++.h>
using namespace std;
signed main(){
	
	int n;
	cin>>n;
	int mod = n%1000;
	n/=1000;
	cout<<n<<" "<<mod<<endl;
	int ans = 1;
	for(int i=n;i>=1;i-=2){
		
		ans*=i;
		ans%=mod;
	}
	cout<<ans<<endl;
}
