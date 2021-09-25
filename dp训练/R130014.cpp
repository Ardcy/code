#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[350000];
int sum[35000];
signed main(){
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		a[i+1]=s[i]-'0';
	}
	int ans=0;
	if(a[1]%4==0)ans+=1;
	for(int i=2;i<=s.length();i++){
		if(a[i]%4==0)ans+=1;
		if((a[i-1]*10+a[i])%4==0)ans+=i-1;
	}
	cout<<ans<<endl;
	
	
}
