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


signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		string t;
		cin>>s>>t;
		
		int l=s.length();
		vector<int>Q;
		
		if(l == 1){
			if(s[0]!=t[0])Q.pb(1);
		}
		else if(l&1){
			int f = 0;
			if(s[l/2]!=t[l/2]){
				Q.pb(n);Q.pb(l/2);
				f=1-f;
			}
			
			for(int i=l/2-1;i>=0;i--){
				if((f==0?s[i]:(s[i]=='1'?'0':'1'))!=t[i]){
					Q.pb(n);Q.pb(n-1-i);
					f=1-f;
				}
			}
			f=0;
			for(int i=l/2+1;i<n;i++){
				if((f==0?s[i]:(s[i]=='1'?'0':'1'))!=t[i]){
					Q.pb(i);Q.pb(n);
					f=1-f;
				}
				
			}
		}else{
			int f = 0;
			for(int i=l/2-1;i>=0;i--){
				if((f==0?s[i]:(s[i]=='1'?'0':'1'))!=t[i]){
					Q.pb(n);Q.pb(n-1-i);
					f=1-f;
				}
			}
			f = 0;
			for(int i=l/2;i<n;i++){
				if((f==0?s[i]:(s[i]=='1'?'0':'1'))!=t[i]){
					Q.pb(i);Q.pb(n);
					f = 1 - f;
				}
			}			
		}
		cout<<Q.size()<<" ";
		for(auto p:Q)cout<<p<<" ";
		cout<<endl;
		
	}
	return 0;
}


