#include<bits/stdc++.h>
using namespace std;
int a[1500000];
int main(){
	int t;
	cin>>t;
	string s;
	int cnt=0;
	while(t--){
		cnt=0;
		cin>>s;
		for(int i=0;i<s.length();i++){
			if(s.substr(i,5)=="twone")a[cnt++]=i+3,i+=4;
			else if(s.substr(i,3)=="two")a[cnt++]=i+2;
			else if(s.substr(i,3)=="one")a[cnt++]=i+2;
		}
		cout<<cnt<<endl;
		for(int i=0;i<cnt;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
} 
