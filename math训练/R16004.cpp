#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1050000];
signed main(){
	int k;
	string s;
	cin>>k>>s;
	int ans1=0;
	for(int i=0;i<s.length();i++){
		a[i+1]=a[i]+(s[i]=='1');
		if(s[i]=='0')ans1++;
	}

	int ans = 0;
	int l = s.length();
	for(int i=1;i<=l;i++){
		if(s[i-1]=='0')ans+=(upper_bound(a+i,a+l+1,a[i]+k)-lower_bound(a+i,a+l+1,a[i]+k));
		if(s[i-1]=='1')ans+=(upper_bound(a+i,a+l+1,a[i]+k-1)-lower_bound(a+i,a+l+1,a[i]+k-1));
		cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
