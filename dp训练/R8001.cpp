#include<bits/stdc++.h>
using namespace std;
int a=0;
int main(){
	int c=0,b=0;
	string s;
	cin>>s;
	int ans = 0;
	int b1=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='Q')b1++;
	}
	for(int i=0;i<s.length();i++){
		if(s[i]=='Q'){
			a++;
		}
		if(s[i]=='A'){
			ans+=a*b1-a*a;
		}
		
	}
	cout<<ans<<endl;
}
