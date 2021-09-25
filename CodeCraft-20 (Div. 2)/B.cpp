#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl
#define int long long
signed main(){
	int t;
	int n;
	
	string s;
	string ans,ans1;
	cin>>t;
	while(t--){
		s="";
		ans="";
		ans1="";
		cin>>n;
		cin>>s;
		ans=s;
		int k=1;
		for(int i=1;i<s.length();i++){
			string str = s.substr(0,i);
			if((n-i)%2==1)reverse(str.begin(),str.end());
			ans1 = s.substr(i,s.length())+str;
			if(ans>ans1)ans=ans1,k=i+1;
		}
		cout<<ans<<endl;
		cout<<k<<endl;
	}
	
}
