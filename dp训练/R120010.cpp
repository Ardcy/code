#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int cnt=0;
	for(int i=1;i<s.length()-1;i++){
		if(s[i]==s[i-1]){
			for(int j=97;j<=122;j++){
				if((char)j!=s[i-1]&&(char)j!=s[i+1])
				{
					s[i]=(char)j;
					break;
				}
			}
			
		}
	}
	cout<<s<<endl;
}
 
