#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	string s;
	cin>>s;
	int a=0,b=0,c=0,d=0;
	for(int i=0;i<s.length();i++){
		
		if(s[i]=='S')a=1;
		if(s[i]=='W')b=1;
		if(s[i]=='E')c=1;
		if(s[i]=='N')d=1;
	}
	cout<<b<<c<<endl;
	cout<<a<<d<<endl; 
	if((a==d)&&(c==b))cout<<"Yes"<<endl;else cout<<"No"<<endl;
	return 0;
}
