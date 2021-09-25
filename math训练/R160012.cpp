#include<bits/stdc++.h>
using namespace std;
#define int long long
int ma=0,ans=0;
signed main(){
	int n;
	cin>>n;
	cin>>ma;
	int an;
	ans=ma;
	for(int i=1;i<n;i++){
		cin>>an;
		ma=__gcd(an,ma);
		ans=max(ans,an);
	}
	if((ans/ma-n)%2==1)cout<<"Alice"<<endl;else cout<<"Bob"<<endl;
	return 0;
}
