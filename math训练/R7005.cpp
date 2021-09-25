#include<bits/stdc++.h>
using namespace std;
signed main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='L')a++;else b++; 
	}
	cout<<(a+b)+(a>0&&b>0)<<endl;
	return 0;
}
