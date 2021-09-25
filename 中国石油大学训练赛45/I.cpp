#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		s[i]='A'+(s[i]-'A'+n)%26;
	}
	cout<<s<<endl;
	return 0;
}
