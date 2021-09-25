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
	while(t--){
		int n;
		cin>>n;
		cin>>s;
		string p,p1;
		int l = s.length();
		int l1 = 0;
		for(int i=0;i<l;i++){
			if(s[i]=='0')p+=s[i],l1++;else break;
		}
		int r1 = 0;
		for(int i=l-1;i>=0;i--){
			if(s[i]=='1')p1=s[i]+p1,r1++;else break;
		}
		string ans; 
		if(l1+r1==n)
		ans = p+p1;
		else ans = p+'0'+p1;
		cout<<ans<<endl;
		
		
	}
	return 0;
}


