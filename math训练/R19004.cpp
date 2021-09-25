#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
signed main(){
	int l,r;
	cout<<(1int<<33)<<endl;
	cin>>l>>r;
	if(l==r){
		cout<<0<<endl;
		return 0;
	}
	int w = l^r;
	int w1=pow(2,(int)log2(w));
	int ans = w1;
	l%=w1;
	r%=w1;
	int t = w1>>1;
	while(t){
		if(((l&t)==0)&&((r&t)==0)){
			ans+=t*2-1;
			break;
		}
		else{
			ans+=(((l&t)>0)^((r&t)>0))*t;
			if((((l&t)>0)&&((r&t)>0)))ans+=t;
		}
		t>>=1;
	}
	cout<<ans<<endl;
}
