#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[300000];
int b[300000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		string s="R";
		string l;
		cin>>l;
		s+=l;
		s+='R';
		int a=0,b=0;
		int ans=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='R'){
				a=i;
				ans = max(ans,i-b);
				b=i;
			}
		}
		cout<<ans<<endl;
	}
}
