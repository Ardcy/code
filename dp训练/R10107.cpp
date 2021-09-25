#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,d;
	cin>>n>>d;
	string s;
	cin>>s;
	int cnt = 0,i;
	for(i=0;i<s.length();){
		int c=0;
		for(int j=1;j<=d;j++){
			if(s[i+j]=='1')c=j;
		}
		i=i+c;
		if(c==0)break;
		cnt++;
		
	}
	if(i==s.length()-1)cout<<cnt<<endl;else cout<<-1<<endl;
}
