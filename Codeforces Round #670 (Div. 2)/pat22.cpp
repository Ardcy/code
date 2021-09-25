#include<bits/stdc++.h>
using  namespace std;
map<char,int>P;

signed main(){
	string s,t;
	 
	getline(cin,s);
	getline(cin,t);
	for(auto p:t){
		P[p]=1;
	}	
	for(auto p:s){
		if(P[p]!=1)printf("%c",p);
	}cout<<endl;
}
