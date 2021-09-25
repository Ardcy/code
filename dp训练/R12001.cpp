#include<bits/stdc++.h>
using namespace std;
int d[105000]={0};
int main(){
	string s;
	cin>>s;
	int n;
	cin>>n;
	for(int i=1;i<s.length();i++){
		if(s[i]==s[i-1])d[i]=d[i-1]+1;
		else d[i]=d[i-1];
		//cout<<d[i]<<endl;
	}
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		cout<<d[b-1]-d[a-1]<<endl;
	}
}
