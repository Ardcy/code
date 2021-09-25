#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin>>n;
	int ans = 0;
	while(n){
		if(n-(int)sqrt(n)*(int)sqrt(n)<2){
			cout<<ans+(int)sqrt(n)<<endl;
			return 0;
		}
		else ans+=(int)sqrt(n);
		n-=(int)sqrt(n)*(int)sqrt(n);
		cout<<n<<endl;
	} 
}
