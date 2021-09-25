#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int f = 0,f1 = 0;
		int cnt = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='1')f=1,f1=1;
			if(f==1&&s[i]=='0')cnt++;
			
		}
		int cnt1 = 0;
		f = 0;
		for(int i=s.length()-1;i>=0;i--){
			if(s[i]=='1')f=1;
			if(f==0&&s[i]=='0')cnt1++;
		}
		if(f1==0){
		cout<<0<<endl;continue;}
		cout<<cnt-cnt1<<endl;	
	}
    
    return 0;
}
