#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000];
signed main(){
	string s;
	cin>>s;
	
	for(int i=0;i<s.length();i++){
		if(s[i]>='A'&&s[i]<='Z')a[i+1]+=1;
		a[i+1]+=a[i];
	}
	int ans=10000000000000;
	for(int i=0;i<=s.length();i++){
		ans=min(ans,i-a[i]+(a[s.length()]-a[i]));
	}
	cout<<ans<<endl; 
	return 0;
} 
