#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define int long long
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
string s;
int k;
signed main(){
	
	cin>>s>>k;
	//cout<<s<<endl;
	int l = s.length();
	//cout<<l<<endl;
	int ans1 = 0;
	int lr = qp(2,l);
	//cout<<lr<<endl;
	int inv = qp(lr-1,mod-2);
	//cout<<lr<<" "<<inv<<endl;
	for(int i=0;i<s.length();i++){
		int t = i;
		if(s[i]=='0'||s[i]=='5'){
			int ll = (qp(lr,k)-1+mod)%mod;
			ll *= qp(2,t);
			ll %= mod;
			ll *= inv;
			ll %= mod; 
			ans1+=ll;
			ans1%=mod;
		}
	}
	cout<<ans1<<endl;
	return 0;
}
