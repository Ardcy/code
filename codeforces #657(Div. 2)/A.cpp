#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

string s;
signed main(){
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		cin>>s;
		
		int cnt = 0;
		for(int i=0;i<=n-7;i++){
			if(s.substr(i,7)=="abacaba")cnt++;
			
			
		}
		cout<<cnt<<endl;
		
		
	}
	return 0;
}


