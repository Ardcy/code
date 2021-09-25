#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	string s;
	cin>>s;
	int l = s.length();
	int n = l;
	int ans1 = 0;
	for(int i=0;i<l;i++){
		int t = i+1;
		if(s[i]=='1'){
			ans1+=qp(2,i)*qp(2,2*(n-t));
			ans1%=mod;
		}
	}
	cout<<ans1<<endl;
	return 0;
}
