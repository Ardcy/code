#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
int arr[N];
const int mod = 1e9+7;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1){
			ans *= a,ans%=mod;
		}
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
int pre[200],suf[200];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		string s;
		for(int i=0;i<105;i++){
			pre[i] = 0;
			suf[i] = 0;
		}
		cin>>s;
		
		for(int i=0;i<s.length();i++){
			if(s[i]=='0')pre[i+1]++;
			if(i)pre[i+1] += pre[i];
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			int f = 0;
			for(int i=0;i<l-1;i++){
				if(s[i]==s[l-1]){
					f = 1;
				}
			}
			for(int i=r;i<s.length();i++){
				if(s[r-1]==s[i]){
					f = 1;
				}
			}
			if(f)cout<<"YES"<<endl;else cout<<"NO"<<endl;
			
			
		}
	}
} 
