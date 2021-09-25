#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%mod;a*=a,a%=mod;b>>=1;}return ans;};

signed main(){
	int t;
	cin>>t;
	string s;
	while(t--){
		int n;
		cin>>s;
		char p = s[0];
		int cnt = 0;
		for(int i=1;i<s.length();i++){
			if(s[i]!=s[0])cnt++;
		}
		cout<<cnt<<endl;
		if(cnt){
			int l = s.length()*2;
			for(int i=0;i<l;i++)
			{
				if(i%2)cout<<1;
				else cout<<0;
			}
			cout<<endl;
		}else{
			cout<<s<<endl;
		}
	}
	return 0;
}


